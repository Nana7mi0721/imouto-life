
undefined4
FUN_00551e70(uint param_1,int param_2,short param_3,undefined2 param_4,int param_5,int param_6,
            int param_7)

{
  int *piVar1;
  int *piVar2;
  ushort uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  
  if (DAT_00a834f0 == 0) {
    return 0xffffffff;
  }
  if ((((DAT_00cc50a0 == 0) || ((int)param_1 < 0)) || ((param_1 & 0x7c000000) != DAT_00cc50c8)) ||
     (((DAT_00cc50d0 <= (int)(param_1 & 0xffff) ||
       (piVar2 = *(int **)(DAT_00cc50a4 + (param_1 & 0xffff) * 4), piVar2 == (int *)0x0)) ||
      (*piVar2 * 0x10000 != (param_1 & 0x3ff0000))))) {
    return 0xffffffff;
  }
  piVar2[0xc] = param_2;
  piVar1 = piVar2 + 0xd;
  if (param_6 == 0) {
    *(undefined2 *)piVar1 = 1;
    *(undefined2 *)((int)piVar2 + 0x42) = param_4;
  }
  else {
    *(undefined2 *)piVar1 = 3;
    *(undefined2 *)((int)piVar2 + 0x42) = 0x20;
  }
  uVar3 = (*(ushort *)((int)piVar2 + 0x42) >> 3) * param_3;
  *(ushort *)(piVar2 + 0x10) = uVar3;
  *(short *)((int)piVar2 + 0x36) = param_3;
  piVar2[0xe] = param_5;
  piVar2[0xf] = (uint)uVar3 * param_5;
  *(undefined2 *)(piVar2 + 0x11) = 0;
  if (param_2 == 0) {
    piVar2[0x12] = param_7;
    iVar4 = FUN_0056e030((uint)uVar3 * param_7,"..\\..\\..\\..\\Source\\Library\\Main\\DxSound.cpp",
                         0x25d4);
    piVar2[0x13] = iVar4;
    if (iVar4 == 0) {
      FUN_0056bb10(&DAT_007d6170);
      return 0xffffffff;
    }
  }
  else {
    FUN_00597380(piVar2 + 0x17);
    uVar5 = (uint)*(ushort *)(piVar2 + 0x10);
    piVar2[0x16] = 0;
    iVar6 = ((((piVar2[0xf] & 0xffffffU) - 1) + uVar5) / uVar5) * uVar5;
    iVar4 = FUN_005514a0(piVar2 + 0x1e,iVar6,piVar1,0,1,1,0);
    if (iVar4 != 0) {
      FUN_0056bb10(&DAT_007d61d8);
      return 0xffffffff;
    }
    uVar5 = (uint)*(ushort *)(piVar2 + 0x10);
    piVar2[0x8c] = iVar6;
    piVar2[0x8d] = 0;
    piVar2[0x8e] = -1;
    piVar2[0x8f] = 0;
    piVar2[0x90] = 0;
    piVar2[0x93] = 0;
    piVar2[0x91] = (((((uint)(piVar2[0xf] * 0x33) >> 8) - 1) + uVar5) / uVar5) * uVar5;
    piVar2[0x92] = (((((uint)(piVar2[0xf] * 0xc) >> 8) - 1) + uVar5) / uVar5) * uVar5;
    FUN_0056da60(&DAT_00cc50e4,"..\\..\\..\\..\\Source\\Library\\Main\\DxSound.cpp",0x25c6);
    FUN_005807e0(&DAT_00a839d0,piVar2 + 0x12,0xffffffff,piVar2);
    FUN_0056dac0(&DAT_00cc50e4);
  }
  return 0;
}

