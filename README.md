# 🧠 Paradox: Self-Attacking Simulation Engine (PoC)

**Author:** CyberMage07  
**Version:** 1.0  
**License:** For educational and ethical use only

---

## 📌 Overview
Paradox is a simulated self-attacking engine designed for **red teamers**, **cybersecurity researchers**, and **OS developers**. Inspired by the concept of the GBS virus, Paradox enables **controlled adversary simulations** by mimicking privilege escalation, self-exploitation, and persistence — all **in a safe and non-destructive way**.

It can be used to:
- Evaluate self-defense and detection mechanisms
- Test adversary behavior response chains
- Log attack vectors and trace persistence methods

---

## 🔧 Features
- ✅ Simulated privilege escalation checks
- ✅ Fake payload deployment (`payloads/fake_payload.sh`)
- ✅ Simulated persistence via `.bashrc`
- ✅ Structured logging (`logs/paradox.log`)
- ✅ Designed for Linux-based ethical testing environments

---

## 🚀 How to Use

### 🔨 Compile
```bash
gcc paradox.c -o paradox
```

### ▶️ Run
```bash
./paradox
```

Make sure you run it from a user environment. No root privileges required.

---

## 📁 Project Structure
```
Paradox-Simulator/
├── paradox.c             # Main simulation engine
├── payloads/
│   └── fake_payload.sh   # Simulated payload (executed via bashrc)
├── logs/
│   └── paradox.log       # Activity logs
└── .bashrc (modified)    # Appended with simulated persistence line
```

---

## ⚠️ Ethical Disclaimer
This tool is built **purely for educational and adversary simulation purposes**. It does **not contain any real malware** or system-destructive functionality.

> 🚫 Never use on systems you do not own or have explicit permission to test.  
> ✅ Always disclose tests in organizational environments.

---

## 💬 Credits & Ideas
- Inspired by early GBS-like viral concepts
- Designed by CyberMage07 for **KalkiOS adversary testing module**

For expansions like AI monitoring, socket-based C2 simulation, or extended persistence chaining — open an issue or fork the repo.

---

## 🔗 License
This PoC is shared under **MIT License** for research and academic use.

---

🛡️ *Use with ethics. Code with caution. Red team responsibly.*
