from flask import Flask, jsonify, request

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

        if not isinstance(data.get("value"), (int, float)):
            raise TypeError("List elements must be integer or float")
    
        values.append(data.get("value"))

        return jsonify({
            "message": "element insert",
            "info": data
            }), 201
    
    except TypeError as e:
        return jsonify({
            "message": str(e)
        })

    
@app.route("/list/remove", methods=["DELETE"])
def remove_element():
    try:

        if not values:
            raise IndexError("List is empty")

        data = request.json
        values.remove(data.get("value"))

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
