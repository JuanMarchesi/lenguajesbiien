#include "wifi.h"
#include "ESPAsyncwebserver.h"
#include "asyncTCP.h"

const char* ssid (CESJT);
const char* password (itisjtsmg);
int estado;
int ledV = 1;
int ledR = 2
int ledA = 3;
asyncwebserver = server(80);

const char* pagina_template [] PROGMEN = R"rawliteral(
<!DOCTYPE html>
<html lang="es">

<meta charset="UTF-8">
<head>
    <title>PANEL DE CONTROL DE MAQUINA</title>
    <style>
        body{
            background-color:gray;
        }

        h1{
            font-family: Impact, Haettenschweiler, 'Arial Narrow Bold', sans-serif;
            font-size: 36px;
            text-align:center;
        }

        .boton{
            width:110px;
            height: 40px;
            font-weight:bold;
            border: 2px solid black;
            border-radius: 50px;
        }

        .normal{
            background-color: green;;
        }
        .rojo{
            background-color: red;
        }




    </style>
    <h1>PANEL DE CONTROL DE MAQUINA</h1>
    <div class="PANEL_DE_ESTADO">
        __ESTADO_ACTUAL__
    </div>

    <a href="/normal"><button class="boton normal">normal</button></a>
    <a href="/rojo"></a><button class="boton rojo">rojo<button></a>
</head>
</html>
)rawliteral"

void setup() {
    Serial.begin(115200);
    Serial.print("conectando a...");
    Serial.println(ssid);
    Serial.print(ssid,password);

    int timeout = 20;
    while(wifi.status != WL_Connected && timeout < 0){
        delay(500);
        Serial.print(".");
        timeout--;
    }

    if(wifi.status != WL_Connected){
        serial.print("\nfallo en la conexion. reiniciando");
        delay(1000);
        ESPrestart();
    }

    serial.print("\nwifi conectado!");
    serial.print("direccion IP: hhtp://");
    serial.print(wifi.localIP());

    server.on ("/" HTTP_GET [] (Asyncserverrequest * request) {
        String pagina = pagina_template;
        server -> send (200 "html/text", pagina);
    }
    )

    server.on ("normal" HTTP_GET [] (asyncserverrequest * request){
        pagina.replace("__ESTADO_ACTUAL__", amarillo);
        digitalWrite(ledA, HIGH);
        digitalWrite(ledR, LOW);
        digitalWrite(ledV, LOW);
        server -> redirect ("/")
    }
    )
}

void loop () {
    server.handclient();
    //pongo pa joe
}