
undefined4 FUN_0059b300(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if (DAT_00f3a04c != 0) {
    if (param_2 < 0) {
      if ((DAT_00e80500 != param_1) || (DAT_00e39a54 != 0)) {
        if (param_1 < 1) {
          param_1 = 1;
        }
        FUN_00568ca0(0);
        if (DAT_00dda46c != 0) {
          FUN_00584d70();
        }
        iVar1 = DAT_00e796c0;
        if (DAT_00e796c0 < 4) {
          iVar1 = 4;
        }
        iVar2 = 0;
        if (0 < iVar1) {
          do {
            if ((&DAT_00e80504)[iVar2] != param_1) {
              FUN_005d3ad0(iVar2,10,param_1);
              (&DAT_00e80504)[iVar2] = param_1;
            }
            iVar2 = iVar2 + 1;
          } while (iVar2 < iVar1);
        }
        DAT_00e39a00 = 1;
        DAT_00e80500 = param_1;
      }
    }
    else if ((param_2 < 0x10) && (((&DAT_00e80504)[param_2] != param_1 || (DAT_00e39a54 != 0)))) {
      FUN_005d3ad0(param_2,10,param_1);
      (&DAT_00e80504)[param_2] = param_1;
      DAT_00e80500 = 0xffffffff;
      DAT_00e39a00 = 1;
      return 0;
    }
  }
  return 0;
}

