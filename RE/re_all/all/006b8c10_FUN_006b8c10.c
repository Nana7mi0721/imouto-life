
void FUN_006b8c10(undefined4 *param_1,undefined1 *param_2)

{
  int iVar1;
  
  *(undefined1 *)(param_1 + 0xe) = *param_2;
  *(undefined1 *)((int)param_1 + 0x39) = param_2[1];
  *(undefined1 *)((int)param_1 + 0x3a) = param_2[2];
  *param_1 = *(undefined4 *)(param_2 + 4);
  param_1[1] = *(undefined4 *)(param_2 + 8);
  param_1[2] = *(undefined4 *)(param_2 + 0xc);
  param_1[3] = *(undefined4 *)(param_2 + 0x10);
  param_1[4] = *(undefined4 *)(param_2 + 0x14);
  param_1[5] = *(undefined4 *)(param_2 + 0x18);
  param_1[6] = *(undefined4 *)(param_2 + 0x1c);
  param_1[7] = *(undefined4 *)(param_2 + 0x20);
  param_1[8] = *(undefined4 *)(param_2 + 0x24);
  param_1[9] = *(undefined4 *)(param_2 + 0x28);
  if (*(int *)(param_2 + 0x2c) == 1) {
    param_1[10] = 1;
  }
  else if (*(int *)(param_2 + 0x2c) == 2) {
    param_1[10] = 2;
  }
  else {
    param_1[10] = 0;
  }
  iVar1 = *(int *)(param_2 + 0x30);
  if (iVar1 == 0) {
    param_1[0x19] = 0;
  }
  else if (iVar1 == 2) {
    param_1[0x19] = 2;
  }
  else if (iVar1 == 3) {
    param_1[0x19] = 3;
  }
  else {
    param_1[0x19] = 1;
  }
  param_1[0xb] = *(undefined4 *)(param_2 + 0x34);
  param_1[0xc] = *(undefined4 *)(param_2 + 0x38);
  param_1[0x13] = 1 << ((byte)*(undefined4 *)(param_2 + 0x3c) & 0x1f);
  return;
}

