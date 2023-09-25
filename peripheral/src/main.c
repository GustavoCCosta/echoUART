#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <errno.h>
#include <zephyr/types.h>
#include <sys/printk.h>
#include <sys/byteorder.h>
#include <zephyr.h>
#include <kernel.h>
#include <services/application.h>
#include <services/peripheral.h>

/**
 * @brief Manipula dados recebidos via Bluetooth LE.
 *
 * Esta função é chamada quando dados são recebidos através da conexão Bluetooth LE
 * e os encaminha para o serviço UART Bluetooth correspondente para transmissão.
 *
 * @param buffer Um ponteiro para o buffer que contém os dados recebidos.
 * @param len O comprimento dos dados recebidos.
 */
static void on_ble_rx_data(const uint8_t *buffer, size_t len) {
    ble_uart_service_transmit(buffer, len);
}

/**
 * @brief Manipula o evento de inicialização bem-sucedida do Bluetooth LE.
 *
 * Esta função é chamada quando o Bluetooth LE foi inicializado com sucesso e
 * registra uma função de retorno de chamada para manipular dados recebidos.
 *
 * @param conn Um ponteiro para a estrutura `bt_conn` que representa a conexão Bluetooth LE.
 *             (Este parâmetro é ignorado nesta função.)
 */
static void on_ble_stack_ready(struct bt_conn *conn) {
    (void)conn;
    ble_uart_service_register(on_ble_rx_data);
}

/**
 * @brief Função principal do programa.
 *
 * Esta função principal inicia a aplicação Bluetooth LE registrando uma função de retorno
 * de chamada para manipular o evento de inicialização bem-sucedida do Bluetooth LE.
 * Ela também inicia o serviço BLE UART para receber e transmitir dados.
 */
void main (void) {
    ble_application_start(on_ble_stack_ready);
}