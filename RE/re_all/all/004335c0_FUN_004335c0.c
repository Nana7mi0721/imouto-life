
void FUN_004335c0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_007ad008;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00a1fb40 & 1) == 0) {
    DAT_00a1fb40 = DAT_00a1fb40 | 1;
    local_8 = 0;
    ExceptionList = &local_10;
    FUN_0042bcf0();
  }
  if ((DAT_00a1fb40 & 2) == 0) {
    DAT_00a1fb40 = DAT_00a1fb40 | 2;
    local_8 = 1;
    FUN_004718a0();
    _atexit(FUN_007b3410);
  }
  if ((DAT_00a1fb40 & 4) == 0) {
    DAT_00a1fb40 = DAT_00a1fb40 | 4;
    local_8 = 2;
    FUN_004718a0();
    _atexit(FUN_007b3400);
  }
  if ((DAT_00a1fb40 & 8) == 0) {
    DAT_00a1fb40 = DAT_00a1fb40 | 8;
    local_8 = 3;
    FUN_004718a0();
    _atexit(FUN_007b33f0);
  }
  if ((DAT_00a1fb40 & 0x10) == 0) {
    DAT_00a1fb40 = DAT_00a1fb40 | 0x10;
    local_8 = 4;
    FUN_00471820();
    _atexit(FUN_007b33e0);
  }
  if ((DAT_00a1fb40 & 0x20) == 0) {
    DAT_00a1fb40 = DAT_00a1fb40 | 0x20;
    local_8 = 5;
    FUN_00471820();
    _atexit(FUN_007b33d0);
  }
  if ((DAT_00a1fb40 & 0x40) == 0) {
    DAT_00a1fb40 = DAT_00a1fb40 | 0x40;
    local_8 = 6;
    FUN_004719a0();
    _atexit(FUN_007b33c0);
  }
  if ((DAT_00a1fb40 & 0x80) == 0) {
    DAT_00a1fb40 = DAT_00a1fb40 | 0x80;
    local_8 = 7;
    FUN_00447840();
    _atexit(FUN_007b33b0);
  }
  if ((DAT_00a1fb40 & 0x100) == 0) {
    DAT_00a1fb40 = DAT_00a1fb40 | 0x100;
    local_8 = 8;
    FUN_004441f0();
    _atexit(FUN_007b33a0);
  }
  if ((DAT_00a1fb40 & 0x200) == 0) {
    DAT_00a1fb40 = DAT_00a1fb40 | 0x200;
    local_8 = 9;
    FUN_00471bd0();
    _atexit(FUN_007b3390);
  }
  if ((DAT_00a1fb40 & 0x400) == 0) {
    DAT_00a1fb40 = DAT_00a1fb40 | 0x400;
    local_8 = 10;
    FUN_00472290();
    _atexit(FUN_007b3380);
  }
  if ((DAT_00a1fb40 & 0x800) == 0) {
    DAT_00a1fb40 = DAT_00a1fb40 | 0x800;
    local_8 = 0xb;
    FUN_00472810();
    _atexit(FUN_007b3370);
  }
  if ((DAT_00a1fb40 & 0x1000) == 0) {
    DAT_00a1fb40 = DAT_00a1fb40 | 0x1000;
    local_8 = 0xc;
    FUN_00472ab0(0);
    _atexit(FUN_007b3360);
  }
  if ((DAT_00a1fb40 & 0x2000) == 0) {
    DAT_00a1fb40 = DAT_00a1fb40 | 0x2000;
    local_8 = 0xd;
    FUN_00472c50();
    _atexit(FUN_007b3350);
  }
  local_8 = 0xffffffff;
  if (param_1 == 0) {
    puVar2 = &DAT_00a14600;
    puVar3 = &DAT_00a1f5e8;
    for (iVar1 = 0x156; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    FUN_00472740(&DAT_00a143d8);
    FUN_00472740(&DAT_00a14bb8);
    FUN_00472740(&DAT_00a16538);
    FUN_00473710(&DAT_00a14c24);
    FUN_004744c0(&DAT_00a165bc);
    FUN_00473f10(&DAT_00a16860);
    FUN_004736a0(&DAT_00a14438);
    FUN_00472eb0(&DAT_00a18178);
    FUN_004744e0(&DAT_00a13fa0);
    FUN_00474bc0(&DAT_00a18cc8);
    FUN_00474330(&DAT_00a16758);
    FUN_00474f60(&DAT_00a14c90);
  }
  else if (param_1 == 1) {
    puVar2 = &DAT_00a1f5e8;
    puVar3 = &DAT_00a14600;
    for (iVar1 = 0x156; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    FUN_00472740(&DAT_00a1f588);
    FUN_00472740(&DAT_00a1f528);
    FUN_00472740(&DAT_00a1f4c8);
    FUN_00473710(&DAT_00a1f4b8);
    FUN_004744c0(&DAT_00a1f498);
    FUN_00473f10(&DAT_00a1db80);
    FUN_004736a0(&DAT_00a1da20);
    FUN_00472eb0(&DAT_00a1cee0);
    FUN_004744e0(&DAT_00a1cb18);
    FUN_00474bc0(&DAT_00a1c9a0);
    FUN_00474330(&DAT_00a1c908);
    FUN_00474f60(&DAT_00a1b158);
  }
  ExceptionList = local_10;
  return;
}

