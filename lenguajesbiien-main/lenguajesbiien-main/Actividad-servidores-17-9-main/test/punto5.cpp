#include <arduino.h>
#include <wifi.h>
#include <webserver.h>

const char* ssid = (CESJT);
const char* password = (ITISJTSMG);
int estadonota;

int dor = 1;
int re = 2;
int mi = 3;
int la = 4;
int sol = 5;
int silencio = 6;



const char* pagina_template [] PROGMEN = R"rawliteral(
<!DOCTYPE html>
<html lang="es">

<head>

    <meta charset="UTF-8">
    <meta name="viewport" content="widht=device-widht", initial-scale:1.0>

    <title>GENERADOR DE TONOS</title>

    <style>

        body{
            background-color: green;
        }

        h1{
            text-align: center;
            font-family:Verdana, Geneva, Tahoma, sans-serif;

        }
        .est_nota{
            width:400px;
            height:80px;
            border: 2px
            dashed#000;
            text-align: center;
        }

        .btn_nota{
            width:60px;
            height:150x;
            border: 3px solid black;
            background-color: white;
            margin: 10px;
        }

        .rojo{
            background-color: red;
        }

    </style>

</head>
    <body>
        <span>
            <h1>GENERADOR DE TONOS</h1>
        </span>
        <div>

    <a href='/do'><button class='btn_nota'>Do</button></a>
    <a href='/re'><button class='btn_nota'>re</button></a>                                       </p>           
    <a href='/mi'><button class='btn_nota'>mi</button></a> 
    <a href='/sol'><button class='btn_nota'>sol</button></a>   
    <a href='/la'><button class='btn_nota'>la</button></a>
    <a href='/silencio'><button class='btn_nota rojo'>silencio</button></a>
<div>   
</body>

</html>
)rawliteral";

void setup () {
    Serial.begin(115200);
    pinMode(1,2,3,4,5,6, INPUT);
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
    string pagina = pagina_template;
    pagina.replace("__TOCANDO__",estadonota);
    server.send(200, "text/html", pagina);
    })

    void loop(){
        server.handleClient();
        if(dor = 1){
            estadonota = dor;
        }
    }
}