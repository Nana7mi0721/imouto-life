
undefined4 FUN_0067a9b0(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  if ((param_1 == 0) || (puVar2 = *(undefined4 **)(param_1 + 0x1c), puVar2 == (undefined4 *)0x0)) {
    return 0xfffffffe;
  }
  puVar2[7] = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  if (puVar2[2] != 0) {
    *(uint *)(param_1 + 0x30) = puVar2[2] & 1;
  }
  puVar1 = puVar2 + 0x14c;
  *puVar2 = 0;
  puVar2[1] = 0;
  puVar2[3] = 0;
  puVar2[5] = 0x8000;
  puVar2[8] = 0;
  puVar2[0xe] = 0;
  puVar2[0xf] = 0;
  puVar2[0x1b] = puVar1;
  puVar2[0x14] = puVar1;
  puVar2[0x13] = puVar1;
  puVar2[0x6f0] = 1;
  puVar2[0x6f1] = 0xffffffff;
  return 0;
}

