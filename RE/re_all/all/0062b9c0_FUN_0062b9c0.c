
void __thiscall FUN_0062b9c0(int *param_1,byte *param_2)

{
  int *piVar1;
  int iVar2;
  
  if ((3 < *param_1) && ((*param_2 & 8) == 0)) {
    iVar2 = *param_1 + -1;
    *param_1 = iVar2;
    piVar1 = param_1 + iVar2 * 4 + 1;
    param_1[0xd] = *piVar1;
    param_1[0xe] = piVar1[1];
    param_1[0xf] = piVar1[2];
    param_1[0x10] = piVar1[3];
    piVar1 = param_1 + *param_1 * 4 + 0x15;
    param_1[0x21] = *piVar1;
    param_1[0x22] = piVar1[1];
    param_1[0x23] = piVar1[2];
    param_1[0x24] = piVar1[3];
    piVar1 = param_1 + *param_1 * 4 + 0x29;
    param_1[0x35] = *piVar1;
    param_1[0x36] = piVar1[1];
    param_1[0x37] = piVar1[2];
    param_1[0x38] = piVar1[3];
  }
  if ((2 < *param_1) && ((*param_2 & 4) == 0)) {
    iVar2 = *param_1 + -1;
    *param_1 = iVar2;
    piVar1 = param_1 + iVar2 * 4 + 1;
    param_1[9] = *piVar1;
    param_1[10] = piVar1[1];
    param_1[0xb] = piVar1[2];
    param_1[0xc] = piVar1[3];
    piVar1 = param_1 + *param_1 * 4 + 0x15;
    param_1[0x1d] = *piVar1;
    param_1[0x1e] = piVar1[1];
    param_1[0x1f] = piVar1[2];
    param_1[0x20] = piVar1[3];
    piVar1 = param_1 + *param_1 * 4 + 0x29;
    param_1[0x31] = *piVar1;
    param_1[0x32] = piVar1[1];
    param_1[0x33] = piVar1[2];
    param_1[0x34] = piVar1[3];
  }
  if ((1 < *param_1) && ((*param_2 & 2) == 0)) {
    iVar2 = *param_1 + -1;
    *param_1 = iVar2;
    piVar1 = param_1 + iVar2 * 4 + 1;
    param_1[5] = *piVar1;
    param_1[6] = piVar1[1];
    param_1[7] = piVar1[2];
    param_1[8] = piVar1[3];
    piVar1 = param_1 + *param_1 * 4 + 0x15;
    param_1[0x19] = *piVar1;
    param_1[0x1a] = piVar1[1];
    param_1[0x1b] = piVar1[2];
    param_1[0x1c] = piVar1[3];
    piVar1 = param_1 + *param_1 * 4 + 0x29;
    param_1[0x2d] = *piVar1;
    param_1[0x2e] = piVar1[1];
    param_1[0x2f] = piVar1[2];
    param_1[0x30] = piVar1[3];
  }
  if ((0 < *param_1) && ((*param_2 & 1) == 0)) {
    iVar2 = *param_1 + -1;
    *param_1 = iVar2;
    piVar1 = param_1 + iVar2 * 4 + 1;
    param_1[1] = *piVar1;
    param_1[2] = piVar1[1];
    param_1[3] = piVar1[2];
    param_1[4] = piVar1[3];
    piVar1 = param_1 + *param_1 * 4 + 0x15;
    param_1[0x15] = *piVar1;
    param_1[0x16] = piVar1[1];
    param_1[0x17] = piVar1[2];
    param_1[0x18] = piVar1[3];
    piVar1 = param_1 + *param_1 * 4 + 0x29;
    param_1[0x29] = *piVar1;
    param_1[0x2a] = piVar1[1];
    param_1[0x2b] = piVar1[2];
    param_1[0x2c] = piVar1[3];
  }
  return;
}

