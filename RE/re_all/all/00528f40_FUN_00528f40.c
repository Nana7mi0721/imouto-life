
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

int __fastcall FUN_00528f40(int param_1)

{
  int iVar1;
  int local_188c;
  undefined4 local_1008;
  undefined4 local_1004;
  undefined1 local_1000 [2048];
  undefined1 local_800 [2044];
  undefined4 uStack_4;
  
  uStack_4 = 0x528f4a;
  FUN_00514f20();
  if (local_188c != -1) {
    iVar1 = FUN_005245d0(param_1 + 0xac,*(undefined4 *)(param_1 + 0x128),
                         *(undefined4 *)(param_1 + 300),local_1008,local_1004,
                         *(undefined4 *)(param_1 + 0x184));
    if (iVar1 == 0) {
      FUN_00518060(param_1 + 0x124,*(undefined4 *)(param_1 + 300),*(undefined4 *)(param_1 + 0x134),0
                   ,0,0,*(undefined4 *)(param_1 + 0x138),*(undefined4 *)(param_1 + 0x13c),
                   *(undefined4 *)(param_1 + 0x140),*(undefined4 *)(param_1 + 0x144),local_1008,
                   local_1004,*(undefined4 *)(param_1 + 0x188),*(undefined4 *)(param_1 + 0x94),
                   0xffffffff);
    }
    FUN_00515110(param_1);
    return iVar1;
  }
  if (*(int *)(param_1 + 0x128) == 0) {
    if (*(int *)(param_1 + 0x134) == 0) {
      if (*(int *)(param_1 + 0x138) == 0) {
        return -1;
      }
    }
    else {
      iVar1 = thunk_FUN_00572540(*(int *)(param_1 + 0x134),0,1,0);
      if (iVar1 == 0) {
        FUN_0052d510(*(undefined4 *)(param_1 + 0x134),local_800,0x800,0);
        if (DAT_00aba250 == 0) {
          FUN_0057a980();
        }
        FUN_005764b0(local_800,0xffffffff,DAT_00aba250,local_1000,0x800,0x4b0);
        FUN_0056bca0(&DAT_007d58a8,local_1000);
        return -1;
      }
      thunk_FUN_00571d20(iVar1);
    }
    iVar1 = FUN_00527a30(param_1,*(undefined4 *)(param_1 + 300),*(undefined4 *)(param_1 + 0x134),
                         *(undefined4 *)(param_1 + 0x138),*(undefined4 *)(param_1 + 0x13c),
                         *(undefined4 *)(param_1 + 0x184),*(undefined4 *)(param_1 + 0x18c),0);
    if (-1 < iVar1) {
      FUN_00527df0(*(undefined4 *)(param_1 + 300),0,0,0,0,0);
      return 0;
    }
  }
  return -1;
}

