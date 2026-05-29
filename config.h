/* See LICENSE file for copyright and license details. */

const unsigned int interval = 3000;

static const char unknown_str[] = "";

#define MAXLEN 2048

static const struct arg args[] = {
    { datetime,       "[%s]",           "%a %d %b"    },
    { datetime,       " %s  ",          "%H:%M"       },

    { run_command,    " %s°C  ",
      "[ -r /sys/class/thermal/thermal_zone0/temp ] && "
      "awk '{print $1/1000}' /sys/class/thermal/thermal_zone0/temp" },

    { run_command,    "󰤨 %s  ",
      "nmcli -t -f ACTIVE,SSID,SIGNAL dev wifi 2>/dev/null | "
      "awk -F: '/^yes/{print $2, $3\"%\"; exit}'" },

    { run_command,    " %s  ",
      "pamixer --get-volume-human" },

    { run_command,    " %s  ",
      "pamixer --default-source --get-volume-human 2>/dev/null" },

    { run_command,    " %s%%  ",
      "for _ in 1 2 3; do "
      "  v=$(cat /sys/class/power_supply/BAT1/capacity 2>/dev/null); "
      "  [ \"$v\" -gt 0 ] && echo \"$v\" && exit 0; "
      "  sleep 0.15; "
      "done; exit 0" },

    { run_command,    " %s  ",
      "bluetoothctl show 2>/dev/null | grep -q 'Powered: yes' && "
      "printf on || printf off" },

    { cpu_perc,       " %s%%  ",       NULL          },
    { ram_perc,       " %s%%  ",       NULL          },
};
