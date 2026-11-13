# Voice-Message Heart

A heart-shaped gift: press the big button in the middle and it plays a recorded voice
message while 10 red LEDs light up around the edge, stay on for about the length of the
message, then slowly fade out. Hold the small **REC** button to record a new message
(up to 10 s). The message stays even with the batteries removed.

![Front](docs/pcb-front.png)

| File | What it is |
|---|---|
| `voice-heart.kicad_pro` | KiCad 10 project (open this) |
| `voice-heart.kicad_sch` | Schematic, with supplier and price fields on every part |
| `voice-heart.kicad_pcb` | Heart-shaped 2-layer PCB, 96 x 86 mm, all through-hole |
| `voice-heart.kicad_sym` / `voice-heart.pretty/` | ISD1820 module symbol and footprint (blue 2x6-header board) |
| `voice-heart.kicad_dru` | Lion Circuits manufacturing limits as KiCad DRC rules |
| `docs/voice-heart-schematic.pdf` | Printable schematic |
| `docs/voice-heart-bom.csv` | Parts list |
| `docs/pcb-front.png`, `docs/pcb-back.png` | 3D renders |
| `fab/voice-heart-gerbers.zip` | Upload this to the PCB maker |

## How it works

| Block | Parts | What it does |
|---|---|---|
| Power | 3x AAA box with switch and screw lid (4.5 V) | No coin cells, so nothing small and dangerous to swallow |
| Voice | ISD1820 module (blue board) with its 8 Ω speaker plugged into the module | Records from its onboard mic while REC is held, plays the whole message on a PLAY press |
| Buttons | SW1 12 mm PLAY (front centre), SW2 6 mm REC (left lobe) | Both pull the module's REC/PLAYE pins up to the battery (active HIGH) |
| Glow timer | D11, D12, C1 22 µF, R11 470k, Q1 BC517 | A press charges C1; C1 drains slowly into Q1's base, so Q1 keeps the LEDs on about 10 s, then they fade over about 15 s |
| Heart LEDs | D1–D10 red 5 mm, R1–R10 330 Ω | About 6 mA each, about 60 mA total while glowing |

Want a longer glow? Swap C1 for 47 µF (about twice as long). Shorter? Use 10 µF.

Battery life: about 0 mA when idle (and the box has its own switch), about 80 mA while
playing. Hundreds of plays per set of AAAs.

## Ordering the board (Lion Circuits, cheapest settings)

Upload `fab/voice-heart-gerbers.zip` at [lioncircuits.com/quote](https://www.lioncircuits.com/quote)
and **keep every default**:

| Setting | Value |
|---|---|
| Quantity | 5 (minimum) |
| Board size | 96 x 86 mm (read from the Gerbers) |
| Layers | 2, single PCB, 1 design |
| Material / thickness | FR4-TG135, 1.6 mm |
| Copper / finish | 1 oz, HASL |
| Mask colour | **Green** (any other colour adds ₹500) |
| Service | Standard (5–6 days), DTDC Standard shipping (free) |

Quoted 13 Nov 2026: **₹1,652 + 18% GST = ₹1,949** for 5 boards, delivered.

The design is checked against Lion Circuits' standard limits (`voice-heart.kicad_dru`):
6 mil tracks/spacing, 12 mil via-to-track, 0.35 mm minimum drill, 6 mil annular ring,
6 mil silkscreen. The board uses 0.5 mm tracks, 0.3 mm spacing and 0.45 mm via drills, so
it passes with margin.

## Parts (about ₹250–350 plus the PCB)

See `docs/voice-heart-bom.csv`. Ask for the **blue ISD1820 module with speaker**
(Robu.in: "ISD1820 Recording Module Voice Board With On Board Mic and Loud Speaker"),
a **3x AAA box with switch and screw cover**, a BC517 Darlington transistor, and red
5 mm LEDs. No separate speaker is needed.

## Soldering order

Lowest parts first, so the board sits flat on the bench:

1. R1–R11 (resistors, standing upright). R11 is the 470k; the other ten are 330.
2. D11, D12 (1N4148): the black band goes on the side marked **K**.
3. Q1 (BC517): its flat face matches the silkscreen.
4. C1 (22 µF): the long leg (+) goes in the hole marked **+**.
5. D1–D10 (LEDs): the **long leg goes in the round pad**, the short leg in the square pad.
6. SW2 (REC) and SW1 (PLAY, big button).
7. Back side: solder a **2x6 female header** (or two 1x6 strips cut from a 1x40 strip)
   onto U1's 12 holes. The blue ISD1820 plugs in **component side down**, its header pins
   into this socket, so the module covers the back of the PLAY button. The socket
   height keeps the trimmed legs underneath clear of the module.
8. Speaker: plug its white connector into the module's speaker socket and glue the
   speaker to the back.
9. Battery box: red wire to **+**, black to **−** on the BATTERY pads. Glue the box to
   the back; it also works as a stand. A dab of hot glue over each wire joint stops the
   wires breaking.
10. Trim every leg flush on the back, then cover the back with felt or a 3D-printed
    plate so there are no sharp points.

> **Check before plugging in:** the back of the heart labels the module column
> **VCC, GND, FT, P-L, P-E, REC**, matching the blue ISD1820's own silkscreen. The other
> column ("JUMPERS") is the module's RPL/FT jumper pins and is not connected. **Remove
> any jumper caps** on the module, or it will loop or pass the mic through.

## Recording a message

1. Switch the battery box ON.
2. Hold **REC**, wait half a second, speak clearly about 10–20 cm from the module's mic,
   and let go within 10 seconds. The heart glows while you record.
3. Press the big heart button to hear it back.

Record again any time; the new message replaces the old one.

## Safety (for an 8-year-old)

- AAA box with a **screw-shut lid**: batteries can't fall out.
- No coin cells, no LiPo, nothing gets hot (about 80 mA from 4.5 V).
- Trim the legs and cover the back so there are no sharp points.
- Speaker volume is modest, comfortable at arm's length.
