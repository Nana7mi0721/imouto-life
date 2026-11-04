
undefined4 FUN_0055ad40(uint param_1,uint param_2)

{
  int *piVar1;
  int *piVar2;
  
  if (((DAT_00cc50a0 != 0) && (-1 < (int)param_1)) && ((param_1 & 0x7c000000) == DAT_00cc50c8)) {
    if ((int)(param_1 & 0xffff) < DAT_00cc50d0) {
      piVar1 = *(int **)(DAT_00cc50a4 + (param_1 & 0xffff) * 4);
      if ((((piVar1 != (int *)0x0) && (*piVar1 * 0x10000 == (param_1 & 0x3ff0000))) &&
          ((piVar1[0xc] != 1 && ((-1 < (int)param_2 && ((param_2 & 0x7c000000) == DAT_00cc50c8))))))
         && (((int)(param_2 & 0xffff) < DAT_00cc50d0 &&
             (((((piVar2 = *(int **)(DAT_00cc50a4 + (param_2 & 0xffff) * 4), piVar2 != (int *)0x0 &&
                 (*piVar2 * 0x10000 == (param_2 & 0x3ff0000))) && (piVar2[0xc] != 1)) &&
               ((piVar1[0x12] == piVar2[0x12] &&
                (*(short *)((int)piVar1 + 0x36) == *(short *)((int)piVar2 + 0x36))))) &&
              ((*(short *)((int)piVar1 + 0x42) == *(short *)((int)piVar2 + 0x42) &&
               ((short)piVar1[0xd] == (short)piVar2[0xd])))))))) {
        FUN_0056d420(piVar2[0x13],piVar1[0x13],(uint)*(ushort *)(piVar1 + 0x10) * piVar1[0x12]);
        return 0;
      }
    }
  }
  return 0xffffffff;
}

