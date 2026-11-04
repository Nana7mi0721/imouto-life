
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

undefined4 FUN_00571ef0(undefined4 param_1,int *param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined1 *puVar5;
  undefined4 uVar6;
  undefined1 *local_3c10;
  int local_3c0c;
  int local_3c08;
  int local_3c04;
  undefined1 local_3c00 [3072];
  undefined1 local_3000 [3072];
  undefined1 local_2400 [3072];
  undefined1 local_1800 [3072];
  undefined1 local_c00 [3068];
  undefined4 uStack_4;
  
  uStack_4 = 0x571efa;
  if (DAT_00afed04 == 0) {
    FUN_0052d510(param_1,local_3c00,0xc00,0);
    if (DAT_00aba250 == 0) {
      FUN_0057a980();
    }
    puVar5 = local_3c00;
  }
  else {
    FUN_0052d510(param_1,local_3c00,0xc00,0);
    if (DAT_00aba250 == 0) {
      FUN_0057a980();
    }
    FUN_00576e80(DAT_00aba250,local_1800,local_3c00);
    if (DAT_00aba250 == 0) {
      FUN_0057a980();
    }
    puVar5 = local_1800;
  }
  FUN_00577a40(DAT_00aba250,puVar5);
  if ((DAT_00b239b0 == 0) ||
     (iVar1 = FUN_0056d3d0(local_3c00,&DAT_00b22db0,DAT_00b239b0), iVar1 != 0)) {
LAB_00572042:
    local_3c10 = local_3c00;
    iVar1 = 0;
LAB_00572048:
    if (((int)local_3c10 - (int)local_3c00 & 0xfffffffeU) == 0) {
      if (DAT_00aba250 == 0) {
        FUN_0057a980();
      }
      iVar2 = FUN_00572fc0(local_3c00,DAT_00aba250,&local_3c0c);
      iVar3 = 0;
      if (iVar2 != 0) {
        if (DAT_00aba250 == 0) {
          FUN_0057a980();
        }
        iVar3 = FUN_00572fc0(local_3c00 + local_3c0c,DAT_00aba250,&local_3c04);
      }
      if ((iVar2 == 0x5c) && (iVar3 == 0x5c)) {
        if (DAT_00aba250 == 0) {
          FUN_0057a980();
        }
        iVar2 = thunk_FUN_00573310(0x5c,DAT_00aba250,local_2400 + iVar1,0xc00 - iVar1);
        iVar1 = iVar1 + iVar2;
        if (DAT_00aba250 == 0) {
          FUN_0057a980();
        }
        iVar2 = thunk_FUN_00573310(0x5c,DAT_00aba250,local_2400 + iVar1,0xc00 - iVar1);
        iVar1 = iVar1 + iVar2;
        if (DAT_00aba250 == 0) {
          FUN_0057a980();
        }
        thunk_FUN_00573310(0,DAT_00aba250,local_2400 + iVar1,0xc00 - iVar1);
        local_3c10 = local_3c10 + local_3c04 + local_3c0c;
      }
    }
    iVar2 = 0;
    do {
      if (DAT_00aba250 == 0) {
        FUN_0057a980();
      }
      iVar3 = FUN_00572fc0(local_3c10,DAT_00aba250,&local_3c0c);
      local_3c10 = local_3c10 + local_3c0c;
      if (local_3c10 + -local_3c0c != local_3c00) {
        if (iVar3 == 0) {
          return 0xffffffff;
        }
        if ((iVar3 == 0x2f) || (iVar3 == 0x5c)) goto LAB_00572210;
      }
      if (DAT_00aba250 == 0) {
        FUN_0057a980();
      }
      iVar4 = thunk_FUN_00573310(iVar3,DAT_00aba250,local_2400 + iVar1,0xc00 - iVar1);
      iVar1 = iVar1 + iVar4;
      if (DAT_00aba250 == 0) {
        FUN_0057a980();
      }
      iVar3 = thunk_FUN_00573310(iVar3,DAT_00aba250,local_c00 + iVar2,0xc00 - iVar2);
      iVar2 = iVar2 + iVar3;
    } while( true );
  }
  if (DAT_00aba250 == 0) {
    FUN_0057a980();
  }
  iVar1 = FUN_00572fc0(local_3c00 + DAT_00b239b0,DAT_00aba250,&local_3c08);
  if ((iVar1 != 0x5c) && (iVar1 != 0x2f)) goto LAB_00572042;
  iVar2 = FUN_00571aa0(&DAT_00b22db0,0,0xffffffff,0,0,0,0);
  if (iVar2 == -1) {
    return 0xffffffff;
  }
  if (DAT_00afed04 == 0) {
    local_3c10 = local_3c00 + DAT_00b239b0 + local_3c08;
  }
  else {
    local_3c10 = local_1800 + DAT_00b239b0 + local_3c08;
  }
LAB_005724cc:
LAB_005724d0:
  *param_2 = iVar2;
  if (param_3 != 0) {
    uVar6 = *(undefined4 *)((&DAT_00afed08)[iVar2] + 0x40);
    if (DAT_00aba250 == 0) {
      FUN_0057a980();
    }
    FUN_005764b0(local_3c10,0xffffffff,DAT_00aba250,param_3,param_4,uVar6);
  }
  return 0;
LAB_00572210:
  if (iVar2 == 0) {
    return 0xffffffff;
  }
  if (DAT_00aba250 == 0) {
    FUN_0057a980();
  }
  iVar3 = 0xc00 - iVar1;
  thunk_FUN_00573310(0,DAT_00aba250,local_2400 + iVar1,iVar3);
  if (DAT_00aba250 == 0) {
    FUN_0057a980();
  }
  thunk_FUN_00573310(0,DAT_00aba250,local_c00 + iVar2,0xc00 - iVar2);
  FUN_0056d420(local_3000,local_2400,iVar1);
  if (DAT_00aba250 == 0) {
    FUN_0057a980();
  }
  iVar2 = thunk_FUN_00573310(0x2e,DAT_00aba250,local_3000 + iVar1,iVar3);
  iVar2 = iVar2 + iVar1;
  if (DAT_00b22d88 == 0) {
    if (DAT_00afed04 == 0) {
      if (DAT_00aba250 == 0) {
        FUN_0057a980();
      }
      iVar4 = thunk_FUN_00573310(0x44,DAT_00aba250,local_3000 + iVar2,0xc00 - iVar2);
      iVar2 = iVar2 + iVar4;
      if (DAT_00aba250 == 0) {
        FUN_0057a980();
      }
      iVar4 = thunk_FUN_00573310(0x58,DAT_00aba250,local_3000 + iVar2,0xc00 - iVar2);
      iVar2 = iVar2 + iVar4;
      if (DAT_00aba250 == 0) {
        FUN_0057a980();
      }
      puVar5 = local_3000 + iVar2;
      uVar6 = 0x41;
    }
    else {
      if (DAT_00aba250 == 0) {
        FUN_0057a980();
      }
      iVar4 = thunk_FUN_00573310(100,DAT_00aba250,local_3000 + iVar2,0xc00 - iVar2);
      iVar2 = iVar2 + iVar4;
      if (DAT_00aba250 == 0) {
        FUN_0057a980();
      }
      iVar4 = thunk_FUN_00573310(0x78,DAT_00aba250,local_3000 + iVar2,0xc00 - iVar2);
      iVar2 = iVar2 + iVar4;
      if (DAT_00aba250 == 0) {
        FUN_0057a980();
      }
      puVar5 = local_3000 + iVar2;
      uVar6 = 0x61;
    }
    iVar4 = thunk_FUN_00573310(uVar6,DAT_00aba250,puVar5,0xc00 - iVar2);
    if (DAT_00aba250 == 0) {
      FUN_0057a980();
    }
    thunk_FUN_00573310(0,DAT_00aba250,local_3000 + iVar2 + iVar4,0xc00 - (iVar2 + iVar4));
  }
  else {
    FUN_0056cf70(local_3000 + iVar2,0xc00 - iVar2,&DAT_00b22d08);
  }
  iVar2 = FUN_00571aa0(local_3000,0,0xffffffff,0,0,0,0);
  if (iVar2 != -1) goto LAB_0057248a;
  if (DAT_00aba250 == 0) {
    FUN_0057a980();
  }
  iVar2 = thunk_FUN_00573310(0x5c,DAT_00aba250,local_2400 + iVar1,iVar3);
  iVar1 = iVar1 + iVar2;
  goto LAB_00572048;
LAB_0057248a:
  FUN_0056cf70(&DAT_00b22db0,0xc00,local_3000);
  DAT_00b22dac = iVar2;
  DAT_00b239b0 = iVar1;
  if (DAT_00afed04 == 0) goto LAB_005724d0;
  local_3c10 = local_1800 + ((int)local_3c10 - (int)local_3c00 >> 1) * 2;
  goto LAB_005724cc;
}

