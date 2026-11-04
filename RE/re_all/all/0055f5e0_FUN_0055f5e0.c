
undefined4 FUN_0055f5e0(uint param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 local_4;
  
  iVar2 = FUN_0057e0e0();
  if (iVar2 == 0) {
    return 0xffffffff;
  }
  if ((((DAT_00cc4db0 == 0) || ((int)param_1 < 0)) || ((param_1 & 0x7c000000) != DAT_00cc4dd8)) ||
     (((DAT_00cc4de0 <= (int)(param_1 & 0xffff) ||
       (piVar1 = *(int **)(DAT_00cc4db4 + (param_1 & 0xffff) * 4), piVar1 == (int *)0x0)) ||
      ((*piVar1 * 0x10000 != (param_1 & 0x3ff0000) || (piVar1[4] != 0)))))) {
    return 0xffffffff;
  }
  if (piVar1[0x482] == 1) {
    uVar3 = FUN_0055ea30(param_1);
    return uVar3;
  }
  FUN_00551ca0(piVar1 + piVar1[0x94b] * 0x6e + 0x31,&local_4,0);
  uVar3 = FUN_0055bc20(piVar1[0x47e]);
  return uVar3;
}

