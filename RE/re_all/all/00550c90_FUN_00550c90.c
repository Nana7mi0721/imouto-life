
uint FUN_00550c90(int param_1)

{
  int *piVar1;
  uint uVar2;
  int unaff_EBX;
  
  uVar2 = FUN_005809a0(3);
  if (uVar2 == 0xffffffff) {
    return 0xffffffff;
  }
  if ((((DAT_00cc4db0 == 0) || ((int)uVar2 < 0)) || ((uVar2 & 0x7c000000) != DAT_00cc4dd8)) ||
     (((DAT_00cc4de0 <= (int)(uVar2 & 0xffff) ||
       (piVar1 = *(int **)(DAT_00cc4db4 + (uVar2 & 0xffff) * 4), piVar1 == (int *)0x0)) ||
      (*piVar1 * 0x10000 != (uVar2 & 0x3ff0000))))) {
    return 0xffffffff;
  }
  piVar1[0x10] = unaff_EBX;
  piVar1[0x1b] = param_1;
  if (unaff_EBX != 0) {
    FUN_0056da60(&DAT_00a83570,"..\\..\\..\\..\\Source\\Library\\Main\\DxSound.cpp",0x626);
    FUN_005807e0(&DAT_00a83550,piVar1 + 0xc,uVar2,piVar1);
    FUN_0056dac0(&DAT_00a83570);
  }
  return uVar2;
}

