
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0057b440(uint param_1,int param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  undefined8 uVar3;
  undefined1 local_18 [24];
  
  if (((((DAT_00cc5680 == 0) || ((int)param_1 < 0)) || ((param_1 & 0x7c000000) != DAT_00cc56a8)) ||
      ((DAT_00cc56b0 <= (int)(param_1 & 0xffff) ||
       (piVar1 = *(int **)(DAT_00cc5684 + (param_1 & 0xffff) * 4), piVar1 == (int *)0x0)))) ||
     ((*piVar1 * 0x10000 != (param_1 & 0x3ff0000) || (piVar1[4] != 0)))) {
    return 0xffffffff;
  }
  if (param_2 == -1) {
    param_2 = piVar1[0xc];
  }
  if (param_2 == 0) {
    param_2 = 1;
  }
  if ((piVar1[0x33] != 0) && ((param_3 != 1 || (piVar1[0x32] != 0)))) {
    piVar1[0x148] = 0;
    piVar1[0x33] = 0;
    piVar1[0xc] = param_2;
    piVar1[0x32] = 1;
    if (piVar1[0xd] != 0) {
      uVar3 = FUN_00550090();
      *(undefined8 *)(piVar1 + 0x10) = uVar3;
      FUN_005fc490(piVar1[0xe],local_18);
      iVar2 = FUN_005fc4f0(piVar1[0xe]);
      iVar2 = FUN_0050e240((_DAT_007d1090 / *(double *)(piVar1 + 0x18)) * (double)iVar2);
      piVar1[0x12] = iVar2;
      piVar1[0x13] = iVar2 >> 0x1f;
      if (piVar1[0x1a] != 1) {
        param_2 = 1;
      }
      FUN_00561a00(piVar1[0x1c],param_2,0);
      return 0;
    }
    FUN_005da430(piVar1,param_2,param_3);
  }
  return 0;
}

