#include <arduino.h>
#include <wifi.h>
#include <webserver.h>

const char* ssid (CESJT);
const char* password (itisjtsmg);
int tiempo;
int cont;

webserver = server(80);

const char* pagina_template [] PROGMEN = R"rawliteral(
<!DOCTYPE html>
<html lang="es">

<meta charset="UTF-8">

<title>controlador temporizador</title>

<style>
    
    body{
        background-color: gray;
    }

    .titulo{
        font-family: Impact;
        font-weight: bold;
        font-size: 36px;
        text-align: center;
    }

    .boton{
        width: 80px;
        height: 40px;
        font-weight: bold;
        border: 5px solid black;
        border-radius: 50px
    }

    .diez{
        background-color: yellow;
    }

    .treinta{
        background-color: orange;
    }

    .unminuto{
        background-color: green;
    }

</style>
<head>
    <meta http-equiv="refresh" content="1">
    <body>
        <a href='/diez'><button class="boton diez">10s</button></a>
        <a href='/treinta'><button class="boton treinta">30s</button></a>
        <a href='/unminuto'><button class="boton unminuto">60s</button></a>

        <div class="titulo">
            Controlador temporizador
        </div>

    </body>


</head>

</html>
)rawliteral"

void setup(){
    Serial.begin(115200);
    serial.print("conectando a...")
    Serial.println(ssid);
    Serial.print(ssid,password);

    int timeout = 20;
    while(wifi.status != WL_Connected && timeout < 0){
        delay(500);
        Serial.print(".")
        timeout--;
    }

    if(wifi.status != WL_Connected){
        serial.print("\nfallo en la conexion. reiniciando...");
        delay(1000);
        ESPrestart();
    }

    serial.println("\nwifi conectado!");
    serial.print("direccion IP: http://");
    Serial.print(WiFi.localIP())

    server.on("/" []{
       string pagina = pagina_template;
        pagina.replace ("TIEMPO_RESTANTE:XX", tiempo;)
        server.send(200 "text/html", pagina);
    } 
    )
    server.on("/tiempo" []{
        if(tiempo = 10){
            tiempo = cont--;
            server.send(302 "text/plain")
        }
    }
    )
    server.on("/tiempò" []{
        if(tiempo = 30){
            tiempo = cont--;
            server.send(302 "pagina/plain");
        }
    } )
    server.on("/tiempo" []{
        if(tiempo = 60){
            tiempo = cont--
            server.send(302 "text/plain")
        }
    }
    )

}

void loop(){
    server.handclient();
}
// ESTO SEGURO ESTA MAL PERO BUENO


