
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0059af50(int param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  
  if (DAT_00f3a04c == 0) {
    return 0;
  }
  if (param_2 == 0xffffffff) {
    uVar1 = 0;
    do {
      if (param_1 != (&DAT_00e806dc)[uVar1]) break;
      if (param_1 != (&DAT_00e806e0)[uVar1]) {
        uVar1 = uVar1 + 1;
        break;
      }
      if (param_1 != (&DAT_00e806e4)[uVar1]) {
        uVar1 = uVar1 + 2;
        break;
      }
      if (param_1 != (&DAT_00e806e8)[uVar1]) {
        uVar1 = uVar1 + 3;
        break;
      }
      uVar1 = uVar1 + 4;
    } while (uVar1 < 0x10);
    if ((uVar1 != 0x10) || (DAT_00e39a54 != 0)) {
      FUN_00568ca0(0);
      if (DAT_00dda46c != 0) {
        FUN_00584d70();
      }
      DAT_00e806dc = param_1;
      DAT_00e806e0 = param_1;
      DAT_00e806e4 = param_1;
      DAT_00e806e8 = param_1;
      DAT_00e806ec = param_1;
      DAT_00e806f0 = param_1;
      DAT_00e806f4 = param_1;
      DAT_00e806f8 = param_1;
      _DAT_00e806fc = param_1;
      _DAT_00e80700 = param_1;
      _DAT_00e80704 = param_1;
      _DAT_00e80708 = param_1;
      _DAT_00e8070c = param_1;
      _DAT_00e80710 = param_1;
      _DAT_00e80714 = param_1;
      _DAT_00e80718 = param_1;
      DAT_00e39a00 = 1;
      iVar2 = FUN_005d3ad0(0,3,param_1);
      uVar1 = 1;
      do {
        FUN_005d3ad0(uVar1,3,param_1);
        uVar1 = uVar1 + 1;
      } while (uVar1 < 0x10);
      return -(uint)(iVar2 != 0);
    }
  }
  else {
    if (0xf < param_2) {
      return -1;
    }
    if ((param_1 != (&DAT_00e806dc)[param_2]) || (DAT_00e39a54 != 0)) {
      FUN_00568ca0(0);
      if (DAT_00dda46c != 0) {
        FUN_00584d70();
      }
      (&DAT_00e806dc)[param_2] = param_1;
      DAT_00e39a00 = 1;
      iVar2 = FUN_005d3ad0(param_2,3,param_1);
      return -(uint)(iVar2 != 0);
    }
  }
  return 0;
}

