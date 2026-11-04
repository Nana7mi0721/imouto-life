
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

int __thiscall FUN_00529470(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int local_1890;
  int local_188c;
  undefined1 local_1888 [1088];
  undefined1 local_1448 [1088];
  undefined4 local_1008;
  int local_1004;
  undefined1 local_1000 [2048];
  undefined1 local_800 [2044];
  undefined4 uStack_4;
  
  uStack_4 = 0x52947a;
  FUN_00514f20();
  if (local_188c == -1) {
    if (*(int *)(param_1 + 0x134) != 0) {
      FUN_0052d510(*(int *)(param_1 + 0x134),local_1000,0x800,0);
      if (DAT_00aba250 == 0) {
        FUN_0057a980();
      }
      FUN_005764b0(local_1000,0xffffffff,DAT_00aba250,local_800,0x800,0x4b0);
      FUN_0056bca0(&DAT_007d58cc,local_800);
    }
    return -1;
  }
  iVar1 = FUN_00528020(param_1 + 0xac,*(undefined4 *)(param_1 + 0x128),
                       *(undefined4 *)(param_1 + 0x130),local_1008,local_1004,
                       *(undefined4 *)(param_1 + 0x160),*(undefined4 *)(param_1 + 0x164),
                       *(undefined4 *)(param_1 + 0x168),*(undefined4 *)(param_1 + 0x16c),
                       *(undefined4 *)(param_1 + 0x170),*(undefined4 *)(param_1 + 0x174),
                       *(undefined4 *)(param_1 + 0x178),*(undefined4 *)(param_1 + 0x17c),
                       *(undefined4 *)(param_1 + 0x180),*(undefined4 *)(param_1 + 0x184),
                       *(undefined4 *)(param_1 + 0x188),param_2);
  if (iVar1 == 0) {
    FUN_00518060(param_1 + 0x124,**(undefined4 **)(param_1 + 0x180),*(undefined4 *)(param_1 + 0x134)
                 ,0,0,0,*(undefined4 *)(param_1 + 0x138),*(undefined4 *)(param_1 + 0x13c),
                 *(undefined4 *)(param_1 + 0x140),*(undefined4 *)(param_1 + 0x144),local_1008,
                 local_1004,*(undefined4 *)(param_1 + 0x188),*(undefined4 *)(param_1 + 0x94),
                 0xffffffff,param_2);
    iVar2 = 1;
    if (1 < *(int *)(param_1 + 0x160)) {
      do {
        FUN_00518060(param_1 + 0x124,(*(undefined4 **)(param_1 + 0x180))[iVar2],0,0,0,0,0,0,0,0,0,0,
                     0,0,**(undefined4 **)(param_1 + 0x180),param_2);
        iVar2 = iVar2 + 1;
      } while (iVar2 < *(int *)(param_1 + 0x160));
    }
  }
  if (local_1890 != 0) {
    FUN_005421c0(local_1888);
    FUN_005421c0(local_1448);
    return iVar1;
  }
  if ((*(int *)(param_1 + 0x188) == 1) && (FUN_00541150(local_1008), local_1004 != 0)) {
    FUN_00541150(local_1004);
  }
  return iVar1;
}

