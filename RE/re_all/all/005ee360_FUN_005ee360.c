
void FUN_005ee360(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  if (0 < DAT_00a37da8) {
    puVar1 = param_1;
    do {
      *puVar1 = *(undefined4 *)(((int)&DAT_00e8063c - (int)param_1) + (int)puVar1);
      iVar2 = iVar2 + 1;
      puVar1 = puVar1 + 1;
    } while (iVar2 < DAT_00a37da8);
  }
  iVar3 = 1;
  iVar2 = DAT_00a37da8;
  if (1 < DAT_00a37da8) {
    do {
      if ((&DAT_00e8063c)[iVar3] != 0) {
        FUN_005a0bd0(0,iVar3);
        iVar2 = DAT_00a37da8;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar2);
  }
  param_1[0xd] = DAT_00a37fc0;
  param_1[9] = DAT_00a380cc;
  param_1[10] = DAT_00a380d0;
  param_1[0xe] = DAT_00a380bc;
  param_1[0xb] = DAT_00a380ec;
  param_1[0xc] = DAT_00a380f0;
  param_1[0xf] = DAT_00a380a0;
  param_1[0x10] = (uint)(DAT_00a38de0 == 0);
  FUN_00516290(0);
  FUN_005160d0(0xe,0xff);
  FUN_005160a0(1);
  FUN_00516160(8,0);
  FUN_00516400(0);
  FUN_00516dc0(0);
  iVar2 = FUN_00567b30();
  if (iVar2 == 0) {
    return;
  }
  FUN_005d3910(param_1 + 8);
  FUN_005d38f0();
  return;
}

