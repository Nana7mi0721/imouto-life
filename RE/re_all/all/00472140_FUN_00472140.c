
void __fastcall FUN_00472140(undefined4 *param_1)

{
  undefined2 uVar1;
  int local_c;
  
  if (DAT_0084b230 / DAT_0084b248 < 800) {
    local_c = ((DAT_0084b230 / DAT_0084b248 < 0x280) - 1 & 10) + 0xc;
  }
  else {
    local_c = 0x1c;
  }
  param_1[0x246] = local_c;
  param_1[0x2c2] = ((DAT_0084b230 / DAT_0084b248 < 0x280) - 1 & 5) + 5;
  *(short *)((int)param_1 + 0x94e) = (short)DAT_0084b264 * 10;
  uVar1 = FUN_004fe844();
  *(undefined2 *)(param_1 + 0x254) = uVar1;
  uVar1 = FUN_004fe844();
  *(undefined2 *)(param_1 + 599) = uVar1;
  uVar1 = FUN_004fe844();
  *(undefined2 *)((int)param_1 + 0x95e) = uVar1;
  param_1[0x275] = 0;
  param_1[0x286] = 100;
  param_1[0x285] = 100;
  param_1[0x284] = 100;
  param_1[0x2bf] = 0;
  *param_1 = 0x3f800000;
  param_1[0x245] = DAT_00a117b8;
  FUN_0042f720(param_1[0x245]);
  return;
}

