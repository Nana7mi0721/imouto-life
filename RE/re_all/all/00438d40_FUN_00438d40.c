
undefined4 FUN_00438d40(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_1 < 0xf42401) {
    if ((param_1 < 0x186a05) || (0x186a09 < param_1)) {
      if (param_1 < 3000000) {
        uVar1 = 1;
      }
      else if ((param_1 < 15000000) || (15999999 < param_1)) {
        if ((param_1 < 3000000) || (3999999 < param_1)) {
          if (((param_1 < 9100000) || (9199999 < param_1)) || (param_1 % 10 != 9)) {
            if ((param_1 < 9900000) || (9999999 < param_1)) {
              uVar1 = 1;
            }
            else {
              uVar1 = 0;
            }
          }
          else {
            uVar1 = 0;
          }
        }
        else {
          uVar1 = 0;
        }
      }
      else if ((param_1 % 100 < 5) || (9 < param_1 % 100)) {
        uVar1 = 1;
      }
      else {
        uVar1 = 0;
      }
    }
    else {
      uVar1 = 0;
    }
  }
  else if ((param_1 < 1000000000) || (1099999999 < param_1)) {
    if ((param_1 < 1100000000) || (1199999999 < param_1)) {
      if ((param_1 < 1300000000) || (1399999999 < param_1)) {
        uVar1 = 1;
      }
      else {
        iVar2 = FUN_00470ee0((param_1 % 1300000000) / 1000000,param_1 % 100);
        if (iVar2 == 1) {
          uVar1 = 1;
        }
        else {
          uVar1 = 0;
        }
      }
    }
    else {
      iVar2 = FUN_00470ee0((param_1 % 1100000000) / 1000000,param_1 % 100);
      if (iVar2 == 1) {
        uVar1 = 1;
      }
      else {
        uVar1 = 0;
      }
    }
  }
  else {
    iVar2 = FUN_00470ee0((param_1 % 1000000000) / 1000000,param_1 % 100);
    if (iVar2 == 1) {
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  return uVar1;
}

