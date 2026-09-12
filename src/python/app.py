from flask import Flask, jsonify, request
from ctypes import CDLL

lib = CDLL("../c/lib_linked_list.so")
lib.initList()

app = Flask(__name__)

values = []

@app.route("/")
def home():
    return jsonify({"message": "welcome"})

@app.route("/list", methods=["GET"])
def get_list():
    return jsonify({"values": values})

@app.route("/list/insert", methods=["POST"])
def insert_element():
    try:
        data = request.json
        value = data.get("value")
        position = data.get("position")

        if not isinstance(value, (int, float)):
            raise TypeError("List elements must be integer or float")

        if position == "end":
            lib.insertAtEnd(value)
        elif position == "init":
            lib.insertAtInit(value)
        else:
            raise ValueError("List element insertion must be at end or init")
        lib.printLinkedList()

        return jsonify({
            "message": "element insert",
            "info": data
            }), 201           

    
    except (TypeError, ValueError) as e:
        return jsonify({
            "message": str(e)
        }), 400

    except Exception as e:
        return jsonify({
            "status": "error",
            "message": "Erro interno ao processar a requisição."
        }), 500

    
@app.route("/list/remove", methods=["DELETE"])
def remove_element():
    try:

        if not values:
            raise IndexError("List is empty")

        data = request.json

        lib.removeNodeList(data.get("value"))

        return jsonify({
            "message": "element removed",
            "info": data
        }), 200

    except ValueError:
        return jsonify({
            "message": f"element {data.get("value")} not found"
        }), 400
    except IndexError as e:
        return jsonify({
            "message": str(e)
        }), 400
    
if __name__ == "__main__":
    app.run(debug=True)
