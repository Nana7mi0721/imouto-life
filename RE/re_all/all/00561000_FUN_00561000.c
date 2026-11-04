
undefined4 FUN_00561000(uint param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 local_4;
  
  iVar2 = FUN_0057e0e0();
  if (((((iVar2 != 0) && (DAT_00cc4db0 != 0)) && (-1 < (int)param_1)) &&
      (((param_1 & 0x7c000000) == DAT_00cc4dd8 && ((int)(param_1 & 0xffff) < DAT_00cc4de0)))) &&
     ((piVar1 = *(int **)(DAT_00cc4db4 + (param_1 & 0xffff) * 4), piVar1 != (int *)0x0 &&
      ((*piVar1 * 0x10000 == (param_1 & 0x3ff0000) && (piVar1[4] == 0)))))) {
    if (piVar1[0x482] != 1) {
      FUN_00551a50(piVar1 + piVar1[0x94b] * 0x6e + 0x31,&local_4);
      return local_4;
    }
    iVar2 = FUN_0055fa80(param_1,piVar1,&local_4,0);
    if (iVar2 != -1) {
      FUN_00551a50(local_4,&local_4);
      return local_4;
    }
  }
  return 0xffffffff;
}

