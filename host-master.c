#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void createApacheVirtualHost(char domain[], char ip[], int port) {
    FILE *fp;
    char filename[100];

    // Create a unique filename for the Apache Virtual Host configuration
    sprintf(filename, "/etc/apache2/sites-available/%s.conf", domain);

    // Open the file for writing
    fp = fopen(filename, "w");

    // Write the Virtual Host configuration to the file
    fprintf(fp, "<VirtualHost *:80>\n");
    fprintf(fp, "\tServerName %s\n", domain);
    fprintf(fp, "\tProxyPreserveHost On\n");
    fprintf(fp, "\tProxyPass / http://%s:%d/\n", ip, port);
    fprintf(fp, "\tProxyPassReverse / http://%s:%d/\n", ip, port);
    fprintf(fp, "</VirtualHost>\n");

    // Close the file
    fclose(fp);

    printf("Apache Virtual Host for %s created.\n", domain);
}

void createPythonVirtualHost(char domain[], char ip[], int port) {
    FILE *fp;
    char filename[100];

    // Create a unique filename for the Python Virtual Host configuration
    sprintf(filename, "/etc/python_virtual_hosts/%s.conf", domain);

    // Open the file for writing
    fp = fopen(filename, "w");

    // Write the Virtual Host configuration to the file
    fprintf(fp, "server {\n");
    fprintf(fp, "\tlisten 80;\n");
    fprintf(fp, "\tserver_name %s;\n", domain);
    fprintf(fp, "\tlocation / {\n");
    fprintf(fp, "\t\tproxy_pass http://%s:%d;\n", ip, port);
    fprintf(fp, "\t\tproxy_set_header Host $host;\n");
    fprintf(fp, "\t\tproxy_set_header X-Real-IP $remote_addr;\n");
    fprintf(fp, "\t\tproxy_set_header X-Forwarded-For $proxy_add_x_forwarded_for;\n");
    fprintf(fp, "\t\tproxy_set_header X-Forwarded-Proto $scheme;\n");
    fprintf(fp, "\t}\n");
    fprintf(fp, "}\n");

    // Close the file
    fclose(fp);

    printf("Python Virtual Host for %s created.\n", domain);
}

int main() {
    char domain[100];
    char ip[16];
    int port;
    int choice;

    // Ask user for domain, IP, and port
    printf("Enter the custom domain: ");
    scanf("%s", domain);
    printf("Enter the device IP: ");
    scanf("%s", ip);
    printf("Enter the port: ");
    scanf("%d", &port);

    // Display menu
    printf("\n[1] For Apache\n");
    printf("[2] For Python\n");
    printf("Choose an option: ");
    scanf("%d", &choice);

    // Depending on user choice, call the respective function
    switch (choice) {
        case 1:
            createApacheVirtualHost(domain, ip, port);
            break;
        case 2:
            createPythonVirtualHost(domain, ip, port);
            break;
        default:
            printf("Invalid option selected.\n");
    }

    return 0;
}
