# 🧊 cub3D

**RayCaster con miniLibX**

Proyecto inspirado en el legendario Wolfenstein 3D (1992), considerado el primer First Person Shooter de la historia.
El objetivo es crear una representación 3D “realista” del interior de un laberinto usando **raycasting**.

---

## 🎯 Objetivo

Cub3D combina **C**, **matemáticas aplicadas**, **manejo de gráficos** y **optimización**, para renderizar una vista en primera persona dentro de un mapa 2D.  
Tu misión: explorar un laberinto, moverte con fluidez, evitar paredes y renderizar correctamente las texturas según la dirección del jugador.

---

## ⚙️ Compilación y ejecución

### 🔧 Requisitos

- **Sistema:** Linux o macOS  
- **Dependencias:** [MiniLibX](https://harm-smits.github.io/42docs/libs/minilibx), biblioteca `math` (`-lm`)  
- **Compilador:** `cc`  
- **Flags:** `-Wall -Wextra -Werror`

### 💻 Compilación
```bash
make
```

### ▶️ Ejecución
```bash
./cub3D maps/map.cub
```

Ejemplo de mapa válido:
```
NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm
F 220,100,0
C 225,30,0

111111
100001
1010N1
111111
```

---

## 🕹️ Controles

| Tecla | Acción |
|-------|--------|
| W | Avanzar |
| S | Retroceder |
| A | Moverse a la izquierda |
| D | Moverse a la derecha |
| ← / → | Girar la cámara |
| ESC | Cerrar el programa |

---

## 🧩 Formato del archivo .cub

Cada archivo .cub contiene los elementos siguientes:

| Identificador | Descripción |
|---------------|-------------|
| NO | Textura del muro Norte |
| SO | Textura del muro Sur |
| WE | Textura del muro Oeste |
| EA | Textura del muro Este |
| F | Color del suelo en formato R,G,B |
| C | Color del techo en formato R,G,B |
| Mapa | Compuesto por 0, 1, N, S, E, W |

📌 El mapa debe estar cerrado por muros (1) y ser el último elemento del archivo.
📌 Los espacios dentro del mapa son válidos y deben manejarse correctamente.
📌 Ante cualquier error, el programa debe mostrar:
Error\n seguido de un mensaje descriptivo.

---

## 🧠 Conceptos técnicos

- **Raycasting:** cálculo de intersecciones entre rayos y muros para determinar profundidad y renderizar perspectiva 3D.
- **MiniLibX:** usada para crear la ventana, manejar eventos, texturas y dibujar píxeles.
- **Trigonometría:** cálculo de ángulos, rotación y dirección del jugador.
- **Parsing robusto:** validación del archivo .cub, detección de errores y gestión de memoria segura.

---

## 🚀 Características

- ✅ Lectura y validación de archivos .cub
- ✅ Carga de texturas para cada orientación
- ✅ Colores configurables para suelo y techo
- ✅ Movimiento fluido en las cuatro direcciones
- ✅ Rotación de cámara con teclas
- ✅ Cierre limpio con ESC o botón de la ventana
- ✅ Detección de errores con mensajes claros

---

## 🌟 Bonus

(Solo evaluados si la parte obligatoria está perfecta)

- 🧭 Minimap dinámico
- 🚪 Colisiones con muros

---

## 📜 Normas y evaluación

- Código conforme a la Norma de 42
- Sin segfaults, leaks, ni double frees
- Cierre limpio del programa
- Gestión de errores con mensajes claros
- Comprensión total del código en defensa
- Bonificaciones solo si el mandatory está 100% correcto

---

## 🕹️ Demo

![Demo](assets/example_cub3d.gif)

---

## 🧠 Inspiración

"Wolfenstein 3D" (Id Software, 1992) — desarrollado por John Carmack y John Romero, pioneros del género FPS.

Cub3D revive ese espíritu con lógica, trigonometría y mucho C.

---

## 👩‍💻 By

Claudia Gil & Giselle Maccha

Estudiantes en 42 Madrid
