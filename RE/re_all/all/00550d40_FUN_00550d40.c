
undefined4 FUN_00550d40(int param_1,uint param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  
  if (DAT_00a834f0 == 0) {
    return 0xffffffff;
  }
  iVar1 = FUN_0057e0e0();
  if (iVar1 == 0) {
    return 0xffffffff;
  }
  FUN_0056da60(&DAT_00cc4df4,"..\\..\\..\\..\\Source\\Library\\Main\\DxSound.cpp",0x6ff);
  if (param_3 == 0) {
    if ((((DAT_00cc4db0 == 0) || ((int)param_2 < 0)) || ((param_2 & 0x7c000000) != DAT_00cc4dd8)) ||
       (((DAT_00cc4de0 <= (int)(param_2 & 0xffff) ||
         (piVar2 = *(int **)(DAT_00cc4db4 + (param_2 & 0xffff) * 4), piVar2 == (int *)0x0)) ||
        ((*piVar2 * 0x10000 != (param_2 & 0x3ff0000) || (piVar2[4] != 0)))))) goto LAB_00550dc1;
  }
  else if (((DAT_00cc4db0 == 0) || ((int)param_2 < 0)) ||
          (((param_2 & 0x7c000000) != DAT_00cc4dd8 ||
           (((DAT_00cc4de0 <= (int)(param_2 & 0xffff) ||
             (piVar2 = *(int **)(DAT_00cc4db4 + (param_2 & 0xffff) * 4), piVar2 == (int *)0x0)) ||
            (*piVar2 * 0x10000 != (param_2 & 0x3ff0000))))))) goto LAB_00550dc1;
  if ((param_1 / (int)(uint)*(ushort *)(piVar2 + 0x480) <= piVar2[0x932]) && (piVar2[0x92d] < 2)) {
    piVar2[0x92f] = 0;
    *(undefined1 *)((int)piVar2 + 0x24d6) = 0;
    piVar2[0x92e] = 0;
    piVar2[0x933] = param_1;
    piVar2[0x930] = param_1;
    *(undefined1 *)(piVar2 + 0x935) = 0;
    FUN_0056dac0(&DAT_00cc4df4);
    return 0;
  }
LAB_00550dc1:
  FUN_0056dac0(&DAT_00cc4df4);
  return 0xffffffff;
}

