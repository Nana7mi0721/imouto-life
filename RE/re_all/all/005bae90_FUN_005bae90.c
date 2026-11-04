
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005bae90(uint param_1)

{
  int iVar1;
  float fVar2;
  
  if (DAT_00f3a070 == 0) {
    return 0xffffffff;
  }
  if ((param_1 != DAT_00f07368) || (DAT_00ef7324 != 0)) {
    iVar1 = *(int *)(DAT_00ef1b84 + 8);
    FUN_00568ca0(0);
    if (DAT_00dda46c != 0) {
      FUN_00584d70();
    }
    fVar2 = (float)_DAT_0081ec30;
    *(float *)(iVar1 + 0x2f0) = (float)(param_1 >> 0x10 & 0xff) / fVar2;
    *(float *)(iVar1 + 0x2f4) = (float)(param_1 >> 8 & 0xff) / fVar2;
    *(float *)(iVar1 + 0x2f8) = (float)(param_1 & 0xff) / fVar2;
    *(undefined4 *)(iVar1 + 0x2fc) = 0x3f800000;
    *(undefined4 *)(DAT_00ef1b84 + 0xc) = 1;
    DAT_00f07368 = param_1;
    DAT_00ef72cc = 1;
  }
  return 0;
}

