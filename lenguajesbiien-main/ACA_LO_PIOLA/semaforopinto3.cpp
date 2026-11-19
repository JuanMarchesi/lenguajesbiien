#include <arduino.h>
#include <wifi.h>
#include <webserver.h>

const char* ssid = (CESJT);
const char* password = (ITISJTSMG);
int color;
int puls_rojo = 2;
const char* pagina_template [] PROGMEN = R"rawliteral(
<!DOCTYPE html>
<html lang="es">

    <meta charset="UFT-8">

    <title>Selector de color RGB</title>

    <style>

        body{
            background-color: black;
        }

        h1{
            color: white;
            text-align: center;
        }

        .btn_color{
            border-radius: 50px;
            width: 80px;
            height: 80px;
            border: 3px white;

        }

        .rojo{
            background-color: red;
        }

        .verde{
            background-color: green;
        }

        .azul{
            background-color: blue;
        }
        .gris{
            background-color: gray;
        }
        .blanco{
            background-color: white;
        }

    </style>
    <head>
        <body>
            <span>
                <h1>GENERADOR DE TONTOS</h1>
            </span>

            <a href='/rojo'><button class='btn_color rojo'>rojo</button></a>
            <a href='/azul'><button class='btn_color azul'>azul</button></a>
            <a href='/gris'><button class='btn_color gris'>gris</button></a>
            <a href='/blanco'><button class='btn_color blanco'>blanco</button></a>
            <a href='/verde'><button class='btn_color verde'>verde</button></a>

            <span>
                <h1>__COLOR_ACTUAL__</h1>
            </span>
        </body>
    </head>

</html>
)rawliteral";

void setup () {
    Serial.begin(115200);
    Serial.print("conectando a")
    Serial.println("ssid")
    Serial.print(ssid, password)

    int timeout = 20;
    while(WiFi.status () != WL_connected && timeout < 0){
        delay(500);
        Serial.print(".");
        timeout --;
    }

    if(WiFi.status () != WL_connected){
        Serial.print("\nla conexion fallo. reiniciando...")
        delay(1000);
        ESPrestart();
    }

    Serial.println("\nwifi conectado")
    Serial.print("direccion IP: http://")
    Serial.println(WiFi.localIP());

    Server.on("/",[](){
    String pagina = pagina_template;
    pagina.replace("__COLOR_ACTUAL__", color)
    server.send(200, "text/html", pagina);
    });
    Server.on("/rojo",[](){
    color=rojo;
    server.send(302, "text/plain", );
    });

    void loop(){
        server.handleClient();
    }