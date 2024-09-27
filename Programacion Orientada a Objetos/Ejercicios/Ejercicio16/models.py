from pydantic import BaseModel

class UsuarioIn(BaseModel):
    usuario: str
    clave: str

class UsuarioOut(BaseModel):
    nombre: str
    apellido: str
