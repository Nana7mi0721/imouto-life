
int FUN_005512e0(uint param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = -1;
  iVar1 = FUN_0057e0e0();
  if (iVar1 != 0) {
    if (param_2 == 0) {
      if ((((DAT_00cc4db0 != 0) && (-1 < (int)param_1)) && ((param_1 & 0x7c000000) == DAT_00cc4dd8))
         && ((((int)(param_1 & 0xffff) < DAT_00cc4de0 &&
              (piVar2 = *(int **)(DAT_00cc4db4 + (param_1 & 0xffff) * 4), piVar2 != (int *)0x0)) &&
             ((*piVar2 * 0x10000 == (param_1 & 0x3ff0000) && (piVar2[4] == 0))))))
      goto LAB_00551395;
    }
    else if (((DAT_00cc4db0 != 0) && (-1 < (int)param_1)) &&
            (((param_1 & 0x7c000000) == DAT_00cc4dd8 &&
             ((((int)(param_1 & 0xffff) < DAT_00cc4de0 &&
               (piVar2 = *(int **)(DAT_00cc4db4 + (param_1 & 0xffff) * 4), piVar2 != (int *)0x0)) &&
              (*piVar2 * 0x10000 == (param_1 & 0x3ff0000))))))) {
LAB_00551395:
      if (piVar2[0x482] == 0) {
        iVar3 = piVar2[0x93e] / (int)(uint)*(ushort *)(piVar2 + 0x480);
      }
      else if (piVar2[0x482] == 1) {
        return piVar2[0x932];
      }
      return iVar3;
    }
  }
  return -1;
}

