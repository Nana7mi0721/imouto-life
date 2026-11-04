
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005b5c40(void)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  FUN_005b5550();
  _DAT_00ddb4c4 = _DAT_007d5550;
  _DAT_00ddb4c8 = _DAT_007d5550;
  DAT_00ddb4cc = 0;
  uVar1 = FUN_00543f70(0xff,0xff,0xff,1,1);
  FUN_0051dc70(0x10,0x10,10,uVar1);
  iVar2 = FUN_005164d0(5,0x10);
  iVar3 = FUN_005164d0(0x1a,0x10);
  uVar1 = FUN_00543f70(DAT_00a37ed8,DAT_00a37edc,DAT_00a37ee0,1);
  FUN_00526390(5,5,0x1c,0x1c,uVar1);
  if (iVar2 != 0) {
    _DAT_00ddb4c4 = _DAT_007d9b98;
  }
  if (iVar3 == 0) {
    _DAT_00ddb4c4 = _DAT_007d9b98;
  }
  if ((iVar2 == 0) && (iVar3 != 0)) {
    return 0;
  }
  uVar1 = FUN_00543f70(0xff,0xff,0xff,1,1);
  FUN_0051dc70(0x10,0x10,10,uVar1);
  iVar2 = FUN_005164d0(5,0x10);
  iVar3 = FUN_005164d0(0x1a,0x10);
  uVar1 = FUN_00543f70(DAT_00a37ed8,DAT_00a37edc,DAT_00a37ee0,1);
  FUN_00526390(5,5,0x1c,0x1c,uVar1);
  if (iVar2 != 0) {
    _DAT_00ddb4c4 = 0;
  }
  if (iVar3 == 0) {
    _DAT_00ddb4c4 = 0;
    return 0;
  }
  return 0;
}

