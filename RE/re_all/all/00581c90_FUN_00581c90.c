
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * FUN_00581c90(undefined4 param_1,int param_2,int param_3)

{
  switch(param_1) {
  case 0:
    break;
  case 1:
    if (param_2 == 0) {
      if (param_3 == 0) {
        if (DAT_00dcb088 == 0) {
          DAT_00dcb088 = 1;
          FUN_00544640(&DAT_00dcac60,0x20,0xff0000,0xff00,0xff,0,0,0,0);
        }
        return &DAT_00dcac60;
      }
      if (DAT_00dcb4b8 == 0) {
        DAT_00dcb4b8 = 1;
        FUN_00544640(&DAT_00dcb090,8,0xff0000,0xff00,0xff,0,0,0,0);
      }
      return &DAT_00dcb090;
    }
    if (param_3 == 0) {
      if (DAT_00dcb8e8 == 0) {
        DAT_00dcb8e8 = 1;
        FUN_00544640(&DAT_00dcb4c0,0x20,0xff0000,0xff00,0xff,0xff000000,0,0,0);
      }
      return &DAT_00dcb4c0;
    }
    if (DAT_00dcbd18 == 0) {
      DAT_00dcbd18 = 1;
      FUN_00544640(&DAT_00dcb8f0,8,0xff0000,0xff00,0xff,0xff000000,0,0,0);
    }
    return &DAT_00dcb8f0;
  case 2:
    if (DAT_00dcac58 == 0) {
      DAT_00dcac58 = 1;
      DAT_00dca834 = 1;
      DAT_00dca835 = 8;
      _DAT_00dca850 = 0;
      DAT_00dca83f = 0;
      _DAT_00dca84c = 0xff;
      DAT_00dca83b = 8;
      DAT_00dca83c = 0;
      _DAT_00dca840 = 0xff;
      DAT_00dca838 = 8;
      DAT_00dca83d = 0;
      _DAT_00dca844 = 0xff;
      DAT_00dca839 = 8;
      DAT_00dca83e = 0;
      _DAT_00dca848 = 0xff;
      DAT_00dca83a = 8;
    }
    return &DAT_00dca830;
  case 3:
    if (DAT_00dca828 == 0) {
      DAT_00dca828 = 1;
      DAT_00dca405 = 0x10;
      DAT_00dca404 = 2;
      _DAT_00dca420 = 0;
      DAT_00dca40f = 0;
      _DAT_00dca41c = 0xffff;
      DAT_00dca40b = 0x10;
      DAT_00dca40c = 0;
      _DAT_00dca410 = 0xffff;
      DAT_00dca408 = 0x10;
      DAT_00dca40d = 0;
      _DAT_00dca414 = 0xffff;
      DAT_00dca409 = 0x10;
      DAT_00dca40e = 0;
      _DAT_00dca418 = 0xffff;
      DAT_00dca40a = 0x10;
    }
    return &DAT_00dca400;
  default:
    return (undefined *)0x0;
  }
  if (param_2 == 0) {
    if (param_3 == 0) {
      if (DAT_00dcc148 == 0) {
        DAT_00dcc148 = 1;
        FUN_00544640(&DAT_00dcbd20,0x10,0xf800,0x7e0,0x1f,0,0,0,0);
      }
      return &DAT_00dcbd20;
    }
    if (DAT_00dcc578 == 0) {
      DAT_00dcc578 = 1;
      FUN_00544640(&DAT_00dcc150,8,0xf800,0x7e0,0x1f,0,0,0,0);
    }
    return &DAT_00dcc150;
  }
  if (param_3 == 0) {
    if (DAT_00dcc9a8 == 0) {
      DAT_00dcc9a8 = 1;
      FUN_00544640(&DAT_00dcc580,0x20,0xf800,0x7e0,0x1f,0xff0000,0,0,0);
    }
    return &DAT_00dcc580;
  }
  if (DAT_00dccdd8 == 0) {
    DAT_00dccdd8 = 1;
    FUN_00544640(&DAT_00dcc9b0,8,0xf800,0x7e0,0x1f,0xff0000,0,0,0);
  }
  return &DAT_00dcc9b0;
}

