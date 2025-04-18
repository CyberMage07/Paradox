

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>

#define VERSION "1.0"
#define LOG_FILE "logs/paradox.log"
#define PAYLOAD_FILE "payloads/fake_payload.sh"
#define PERSISTENCE_FILE ".bashrc"

// Simulated privilege escalation checker
int check_root_privileges() {
    if (geteuid() == 0) {
        printf("[+] Root privileges detected.\n");
        return 1;
    } else {
        printf("[-] Running as a regular user.\n");
        return 0;
    }
}

// Simulated payload deployment
void deploy_fake_payload() {
    mkdir("payloads", 0755);
    FILE *fp = fopen(PAYLOAD_FILE, "w");
    if (fp) {
        fprintf(fp, "#!/bin/bash\necho '[FAKE PAYLOAD] Paradox has triggered an artificial compromise.'\n");
        fclose(fp);
        chmod(PAYLOAD_FILE, 0755);
        printf("[+] Fake payload deployed to %s\n", PAYLOAD_FILE);
    } else {
        perror("[-] Failed to write fake payload");
    }
}

// Simulated persistence via .bashrc
void simulate_persistence() {
    char *home = getenv("HOME");
    if (!home) home = ".";

    char path[512];
    snprintf(path, sizeof(path), "%s/%s", home, PERSISTENCE_FILE);
    
    FILE *bashrc = fopen(path, "a");
    if (bashrc) {
        fprintf(bashrc, "\n# Paradox simulated persistence\n%s\n", PAYLOAD_FILE);
        fclose(bashrc);
        printf("[+] Persistence added to %s\n", path);
    } else {
        perror("[-] Unable to modify .bashrc for persistence");
    }
}

// Activity logging
void log_event(const char *message) {
    mkdir("logs", 0755);
    FILE *log = fopen(LOG_FILE, "a");
    if (log) {
        time_t now = time(NULL);
        fprintf(log, "[%s] %s\n", strtok(ctime(&now), "\n"), message);
        fclose(log);
    }
}

// Simulated system exploitation routine
void run_simulated_exploit() {
    printf("[!] Triggering self-exploitation sequence...\n");
    sleep(1);
    printf("[*] Simulating memory leak...\n");
    sleep(1);
    printf("[*] Faking return address overwrite...\n");
    sleep(1);
    printf("[+] Access escalated (simulated).\n");
    log_event("Simulated exploit triggered and fake elevation performed.");
}

// Initialization banner
void banner() {
    printf("\n=============== PARADOX SIMULATOR v%s ===============\n", VERSION);
    printf("=  Simulating adversary actions for red team training  =\n");
    printf("=  Author: Shaun | Ethical Use Only                 =\n");
    printf("======================================================\n\n");
}

int main() {
    banner();

    int is_root = check_root_privileges();

    deploy_fake_payload();
    run_simulated_exploit();
    simulate_persistence();
    log_event("Simulation completed successfully.");

    printf("\n[✓] Paradox simulation completed. All actions logged.\n");
    return 0;
}
