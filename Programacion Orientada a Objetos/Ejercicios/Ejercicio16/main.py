from fastapi import FastAPI, HTTPException
from motor.motor_asyncio import AsyncIOMotorClient
from models import UsuarioIn, UsuarioOut
from bson import ObjectId

app = FastAPI()

# Conexión a MongoDB
client = AsyncIOMotorClient("mongodb://localhost:27017")
db = client.login_db
collection = db.Usuario

@app.post("/validar_usuario/", response_model=str)
async def validar_usuario(usuario_in: UsuarioIn):
    usuario_dict = usuario_in.dict()
    usuario = await collection.find_one({"usuario": usuario_dict["usuario"], "clave": usuario_dict["clave"]})
    if usuario:
        return f"{usuario['nombre']}::{usuario['apellido']}"
    else:
        return "denegado"

if __name__ == "__main__":
    import uvicorn
    uvicorn.run(app, host="127.0.0.1", port=8000)
