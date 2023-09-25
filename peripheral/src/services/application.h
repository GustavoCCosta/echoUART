#pragma once

#include <zephyr/types.h>
#include <stddef.h>
#include <string.h>
#include <errno.h>
#include <sys/printk.h>
#include <sys/byteorder.h>
#include <sys/util.h>
#include <sys_clock.h>
#include <zephyr.h>
#include <bluetooth/bluetooth.h>
#include <bluetooth/hci.h>
#include <bluetooth/conn.h>
#include <bluetooth/uuid.h>
#include <bluetooth/gatt.h>
#include <kernel.h>

typedef enum {
    kBleConnected,
    kBleDisconnected,
}ble_status;

typedef void (*ble_ready_callback) (struct bt_conn *connection);

/**
 * @brief Inicializa e inicia o aplicativo BLE.
 *
 * Esta função é responsável por iniciar o aplicativo Bluetooth LE, configurar
 * callbacks de conexão e desconexão, bem como registrar o callback de pronto 
 * para ser chamado quando a pilha Bluetooth LE estiver pronta para uso.
 *
 * @param callback Um ponteiro para uma função de callback que será chamada quando
 *                 o Bluetooth LE estiver pronto para uso.
 *
 * @return Um valor de 32 bits que indica o resultado da operação:
 *         - Zero (0) em caso de sucesso.
 *         - Outros valores em caso de erro, por exemplo, se `callback` for nulo.
 */
uint32_t ble_application_start(ble_ready_callback callback);

/**
 * @brief Obtém uma referência para a conexão BLE atual.
 *
 * Esta função retorna um ponteiro para a estrutura `bt_conn` que representa a 
 * conexão Bluetooth LE atual. Essa referência pode ser usada para interagir 
 * com a conexão, como enviar dados ou verificar o status.
 *
 * @return Um ponteiro para a estrutura `bt_conn` representando a conexão Bluetooth LE
 *         atual, ou NULL se não houver nenhuma conexão ativa.
 */
struct bt_conn *ble_get_connection_ref();