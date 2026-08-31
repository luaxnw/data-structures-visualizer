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
    data = request.json
    new_value = {
        "value": data.get("value")
    }
    
    values.append(data.get("value"))
    return jsonify({
        "message": "element insert",
        "info": data
        }), 201
    
@app.route("/list/remove", methods=["POST"])
def remove_element():
    data = request.json
    
    values.pop(data.get("value"))
    return jsonify({
        "message": "element removed",
        "info": data
    }), 201

if __name__ == "__main__":
    app.run(debug=True)
