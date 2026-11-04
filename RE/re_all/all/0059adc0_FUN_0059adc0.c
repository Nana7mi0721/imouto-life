
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0059adc0(int param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  
  if (DAT_00f3a04c == 0) {
    return 0;
  }
  if (param_2 == 0xffffffff) {
    uVar1 = 0;
    do {
      if (param_1 != (&DAT_00e8069c)[uVar1]) break;
      if (param_1 != (&DAT_00e806a0)[uVar1]) {
        uVar1 = uVar1 + 1;
        break;
      }
      if (param_1 != (&DAT_00e806a4)[uVar1]) {
        uVar1 = uVar1 + 2;
        break;
      }
      if (param_1 != (&DAT_00e806a8)[uVar1]) {
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
      DAT_00e8069c = param_1;
      DAT_00e806a0 = param_1;
      DAT_00e806a4 = param_1;
      DAT_00e806a8 = param_1;
      DAT_00e806ac = param_1;
      DAT_00e806b0 = param_1;
      DAT_00e806b4 = param_1;
      DAT_00e806b8 = param_1;
      _DAT_00e806bc = param_1;
      _DAT_00e806c0 = param_1;
      _DAT_00e806c4 = param_1;
      _DAT_00e806c8 = param_1;
      _DAT_00e806cc = param_1;
      _DAT_00e806d0 = param_1;
      _DAT_00e806d4 = param_1;
      _DAT_00e806d8 = param_1;
      DAT_00e39a00 = 1;
      iVar2 = FUN_005d3ad0(0,2,param_1);
      uVar1 = 1;
      do {
        FUN_005d3ad0(uVar1,2,param_1);
        uVar1 = uVar1 + 1;
      } while (uVar1 < 0x10);
      return -(uint)(iVar2 != 0);
    }
  }
  else {
    if (0xf < param_2) {
      return -1;
    }
    if ((param_1 != (&DAT_00e8069c)[param_2]) || (DAT_00e39a54 != 0)) {
      FUN_00568ca0(0);
      if (DAT_00dda46c != 0) {
        FUN_00584d70();
      }
      (&DAT_00e8069c)[param_2] = param_1;
      DAT_00e39a00 = 1;
      iVar2 = FUN_005d3ad0(param_2,2,param_1);
      return -(uint)(iVar2 != 0);
    }
  }
  return 0;
}

