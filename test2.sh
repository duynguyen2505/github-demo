#!bin/bash
while :; do
  cpu_now=($(head -n1 /proc/stat))
  cpu_sum="${cpu_now[@]:1}"
  cpu_sum=$((${cpu_sum// /+}))
  echo "$cpu_sum"
  cpu_delta=$((cpu_sum - cpu_last_sum))
  cpu_idle=$((cpu_now[4] - cpu_last[4]))
  cpu_used=$((cpu_delta - cpu_idle))
  cpu_usage=$((100 * cpu_used / cpu_delta))
  cpu_last=("${cpu_now[@]}")
  cpu_last_sum=$cpu_sum
  echo "CPU usafe at $cpu_usage%"
  if [[ $cpu_usage -lt 50 ]]; then
  echo "OKE";
  elif [[ $cpu_usage -gt 50 && $cpu_usage -lt 70 ]]; then
  echo "warning"; 
  else
  echo "Critical";
  fi

  sleep 1
done
