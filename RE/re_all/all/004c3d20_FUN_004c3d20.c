
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004c3d20(int param_1)

{
  undefined1 uVar1;
  bool bVar2;
  char cVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  int local_1c;
  int local_18;
  int local_10;
  int local_8;
  
  *(undefined4 *)(param_1 + 0x178) = DAT_00a18a64;
  DAT_00a18a64 = 0;
  if (DAT_00a14038 <= *(int *)(param_1 + 0x178)) {
    *(int *)(param_1 + 0x178) = DAT_00a14038 + -1;
  }
  if (*(int *)(param_1 + 0x178) < 0) {
    *(undefined4 *)(param_1 + 0x178) = 0;
  }
  if (DAT_00a14090 != '\0') {
    *(undefined4 *)(param_1 + 0x194) = DAT_00a18ae0;
  }
  cVar3 = operator!=<>(&DAT_00a14014);
  if (cVar3 != '\0') {
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
              ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)(param_1 + 0x38),
               "");
    FUN_004cb840();
  }
  uVar1 = *(undefined1 *)(param_1 + 0x98);
  *(undefined1 *)(param_1 + 0x98) = 1;
  FUN_00494480(0,_DAT_00802e18,_DAT_00802e18,_DAT_007d0a60);
  iVar4 = FUN_004ce080();
  if (iVar4 == 0) {
    *(undefined4 *)(param_1 + 0x178) = DAT_00a1403c;
    FUN_004c1ae0();
    DAT_00a140c0 = *(undefined4 *)(param_1 + 0x178);
  }
  else {
    *(undefined1 *)(param_1 + 0x98) = uVar1;
    local_10 = *(int *)(param_1 + 0x178);
    bVar2 = false;
    for (local_18 = 0; local_18 < DAT_00a14038; local_18 = local_18 + 1) {
      piVar5 = (int *)FUN_004ce990(local_10);
      if (*piVar5 != 0) {
        bVar2 = true;
        break;
      }
      local_10 = (local_10 + 1) % DAT_00a14038;
    }
    if (bVar2) {
      *(int *)(param_1 + 0x178) = local_10;
    }
    local_8 = -1;
    local_1c = 0;
    while( true ) {
      iVar4 = FUN_004ce080();
      if (iVar4 <= local_1c) break;
      piVar5 = (int *)FUN_004ce990(local_1c);
      if (local_8 < *piVar5) {
        piVar5 = (int *)FUN_004ce990(local_1c);
        local_8 = *piVar5;
      }
      local_1c = local_1c + 1;
    }
    *(int *)(param_1 + 0x188) = local_8 + 0x1a;
    iVar4 = FUN_004ce080();
    piVar5 = (int *)FUN_004ce990(iVar4 + -1);
    iVar4 = FUN_004ce080();
    piVar6 = (int *)FUN_004ce990(iVar4 + -1);
    *(int *)(param_1 + 0x18c) = *piVar5 + 0x1a + *piVar6;
  }
  return;
}

