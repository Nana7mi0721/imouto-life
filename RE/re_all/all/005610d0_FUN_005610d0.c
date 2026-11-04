
int FUN_005610d0(undefined4 param_1,uint param_2)

{
  int *piVar1;
  int iVar2;
  int local_4;
  
  iVar2 = FUN_0057e0e0();
  if (((((iVar2 != 0) && (DAT_00cc4db0 != 0)) && (-1 < (int)param_2)) &&
      (((param_2 & 0x7c000000) == DAT_00cc4dd8 && ((int)(param_2 & 0xffff) < DAT_00cc4de0)))) &&
     ((piVar1 = *(int **)(DAT_00cc4db4 + (param_2 & 0xffff) * 4), piVar1 != (int *)0x0 &&
      ((*piVar1 * 0x10000 == (param_2 & 0x3ff0000) && (piVar1[4] == 0)))))) {
    if (piVar1[0x482] == 1) {
      iVar2 = FUN_0055fa80(param_2,piVar1,&local_4,0);
      if (iVar2 == -1) {
        return -1;
      }
      iVar2 = FUN_00551c70(local_4,param_1,&local_4);
    }
    else {
      iVar2 = FUN_00551c70(piVar1 + piVar1[0x94b] * 0x6e + 0x31,param_1,&local_4);
    }
    if (-1 < iVar2) {
      return local_4 + 10000;
    }
  }
  return -1;
}

