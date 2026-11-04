
void FUN_006b88f0(undefined1 *param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  
  *param_1 = *(undefined1 *)(param_2 + 0xe);
  param_1[1] = *(undefined1 *)((int)param_2 + 0x39);
  param_1[2] = *(undefined1 *)((int)param_2 + 0x3a);
  *(undefined4 *)(param_1 + 4) = *param_2;
  *(undefined4 *)(param_1 + 8) = param_2[1];
  *(undefined4 *)(param_1 + 0xc) = param_2[2];
  *(undefined4 *)(param_1 + 0x10) = param_2[3];
  *(undefined4 *)(param_1 + 0x14) = param_2[4];
  *(undefined4 *)(param_1 + 0x18) = param_2[5];
  *(undefined4 *)(param_1 + 0x1c) = param_2[6];
  *(undefined4 *)(param_1 + 0x20) = param_2[7];
  *(undefined4 *)(param_1 + 0x24) = param_2[8];
  *(undefined4 *)(param_1 + 0x28) = param_2[9];
  if (param_2[10] == 1) {
    *(undefined4 *)(param_1 + 0x2c) = 1;
  }
  else if (param_2[10] == 2) {
    *(undefined4 *)(param_1 + 0x2c) = 2;
  }
  else {
    *(undefined4 *)(param_1 + 0x2c) = 0;
  }
  iVar1 = param_2[0x19];
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 0x30) = 0;
  }
  else if (iVar1 == 2) {
    *(undefined4 *)(param_1 + 0x30) = 2;
  }
  else if (iVar1 == 3) {
    *(undefined4 *)(param_1 + 0x30) = 3;
  }
  else {
    *(undefined4 *)(param_1 + 0x30) = 1;
  }
  *(undefined4 *)(param_1 + 0x34) = param_2[0xb];
  *(undefined4 *)(param_1 + 0x38) = param_2[0xc];
  if (param_2[0x13] == 0) {
    *(undefined4 *)(param_1 + 0x3c) = 0;
    return;
  }
  iVar1 = FUN_006b8db0(param_2[0x13] + -1);
  iVar2 = FUN_006b8db0(param_2[0x13] + -1);
  *(uint *)(param_1 + 0x3c) = (-(uint)(iVar1 < 0x1f) & iVar2 - 0x1fU) + 0x1f;
  return;
}

