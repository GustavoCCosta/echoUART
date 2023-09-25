#include <zephyr/types.h>
#include <stddef.h>
#include <string.h>
#include <errno.h>
#include <sys/printk.h>
#include <sys/byteorder.h>
#include <zephyr.h>
#include <stdio.h>

#include <bluetooth/bluetooth.h>
#include <bluetooth/hci.h>
#include <bluetooth/conn.h>
#include <bluetooth/uuid.h>
#include <bluetooth/gatt.h>
#include <kernel.h>
#include <services/application.h>

typedef void (*ble_uart_service_rx_callback) (const uint8_t *data, size_t length);
//static ssize_t client_data(struct bt_conn *conn, const struct bt_gatt_attr *attr, const void *buf, uint16_t len, uint16_t offset, uint8_t flags);
static ssize_t write_test_chrc(struct bt_conn *conn,
				    const struct bt_gatt_attr *attr,
				    const void *buf, uint16_t len,
				    uint16_t offset, uint8_t flags);

/**
 * @brief Manipula a mudança no estado do Cliente Characteristic Configuration (CCC).
 *
 * Esta função é chamada quando o estado do Cliente Characteristic Configuration (CCC)
 * associado a uma característica Bluetooth muda. Ela verifica se as notificações foram
 * habilitadas ou desabilitadas pelo cliente e executa ações apropriadas com base nisso.
 *
 * @param[in] attr  Um ponteiro para a estrutura que representa o atributo Bluetooth.
 * @param[in] value O valor do Cliente Characteristic Configuration (CCC), que indica se
 *                  as notificações foram habilitadas (BT_GATT_CCC_NOTIFY) ou desabilitadas.
 */
static void ble_uart_ccc_changed(const struct bt_gatt_attr *attr, uint16_t value);

/**
 * @brief Registra o serviço UART BLE com um callback de recebimento.
 *
 * Esta função registra o serviço UART BLE e associa um callback de recebimento
 * que será chamado quando dados forem recebidos via conexão Bluetooth.
 *
 * @param[in] callback Um ponteiro para a função de callback que será invocada
 *                     quando dados forem recebidos via Bluetooth.
 *
 * @return 0 se o registro do serviço for bem-sucedido, ou um valor negativo se
 *         ocorrer um erro.
 *
 * @note Antes de chamar esta função, você deve configurar adequadamente a
 *       estrutura `peripheral` com as informações do serviço BLE, como UUIDs e
 *       características.
 */
int ble_uart_service_register(const ble_uart_service_rx_callback callback);

/**
 * @brief Transmite dados pela característica Bluetooth UART.
 *
 * Esta função transmite os dados fornecidos através da característica Bluetooth UART.
 * Os dados são convertidos para letras maiúsculas antes da transmissão.
 *
 * @param buffer Um ponteiro para o buffer contendo a string a ser transformada.
 * @param len    O tamanho da string a ser transformados.
 *
 * @return 0 em caso de sucesso, -1 em caso de erro.
 */
int ble_uart_service_transmit(const uint8_t *buffer, size_t len);