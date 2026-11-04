
undefined4 FUN_00681a20(int *param_1)

{
  undefined1 *puVar1;
  
  *(undefined4 *)(*param_1 + 0x14) = 0x68;
  (**(code **)(*param_1 + 4))(param_1,1);
  if (*(char *)(param_1[0x6b] + 0xc) != '\0') {
    *(undefined4 *)(*param_1 + 0x14) = 0x40;
    (**(code **)*param_1)(param_1);
  }
  puVar1 = (undefined1 *)((int)param_1 + 0xdb);
  do {
    puVar1[-0x10] = 0;
    *puVar1 = 1;
    puVar1[0x10] = 5;
    puVar1 = puVar1 + 1;
  } while ((int)(puVar1 + (-0xdb - (int)param_1)) < 0x10);
  param_1[0x3f] = 0;
  param_1[10] = 0;
  param_1[0x43] = 0;
  *(undefined1 *)(param_1 + 0x44) = 0;
  *(undefined1 *)(param_1 + 0x40) = 0;
  *(undefined1 *)((int)param_1 + 0x101) = 1;
  *(undefined1 *)((int)param_1 + 0x102) = 1;
  *(undefined1 *)((int)param_1 + 0x103) = 0;
  *(undefined2 *)(param_1 + 0x41) = 1;
  *(undefined2 *)((int)param_1 + 0x106) = 1;
  *(undefined1 *)(param_1 + 0x42) = 0;
  *(undefined1 *)((int)param_1 + 0x109) = 0;
  *(undefined1 *)(param_1[0x6b] + 0xc) = 1;
  return CONCAT31((int3)((uint)puVar1 >> 8),1);
}

