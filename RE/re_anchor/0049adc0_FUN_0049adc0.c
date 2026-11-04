// anchor: This font was not generable.

void __thiscall
FUN_0049adc0(int param_1,int param_2,uint param_3,undefined4 param_4,int param_5,int param_6)

{
  uint uVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *pbVar5;
  char *pcVar6;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> *this;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> abStack_a8 [20];
  undefined4 uStack_94;
  char *pcStack_90;
  undefined4 uStack_78;
  undefined1 *puStack_74;
  uint uStack_70;
  undefined4 uStack_6c;
  void *pvStack_68;
  undefined4 uStack_64;
  int iStack_60;
  int iStack_5c;
  int local_3c;
  int local_38;
  uint local_30;
  void *local_18 [4];
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  local_18[3] = &LAB_007af820;
  local_18[2] = ExceptionList;
  iStack_5c = 0x49ade9;
  ExceptionList = local_18 + 2;
  FUN_00530d60();
  if ((int)param_3 < 0x191) {
    local_30 = param_3;
  }
  else {
    local_30 = 400;
  }
  if (param_6 == 0) {
    local_18[0] = (void *)0x0;
    local_18[1] = (void *)0x1;
  }
  else if (param_6 == 1) {
    local_18[0] = (void *)0x22;
    local_18[1] = (void *)0x23;
  }
  else {
    local_18[0] = *(void **)(param_1 + 0x3c0);
    local_18[1] = *(void **)(param_1 + 0x3c4);
  }
  if (0x23 < *(int *)(param_1 + 0x3c8)) {
    FUN_00475c70();
  }
  uVar1 = FUN_004ce080();
  if (uVar1 <= local_30) {
    iStack_5c = 0x49aec4;
    FUN_004ce970();
  }
  iStack_5c = 0x49aee9;
  FUN_004ce990();
  iStack_5c = 0x49af13;
  piVar2 = (int *)FUN_004ce990();
  if (*piVar2 == 0) {
    if (param_5 < 2) {
      local_38 = param_5;
    }
    else {
      local_38 = 1;
    }
    iStack_5c = 0;
    iStack_60 = param_5;
    uStack_64 = *(undefined4 *)(param_1 + 0x3cc + param_2 * 4);
    pvStack_68 = local_18[local_38];
    uStack_6c = param_4;
    uStack_70 = local_30;
    puStack_74 = (undefined1 *)param_2;
    uStack_78 = 0x49af69;
    FUN_004cc4c0();
    puStack_74 = (undefined1 *)0x49af70;
    puStack_74 = (undefined1 *)FUN_004cbb30();
    uStack_78 = 0x49af76;
    uVar3 = FUN_00530810();
    iStack_5c = 0x49afa0;
    puVar4 = (undefined4 *)FUN_004ce990();
    *puVar4 = uVar3;
    iStack_5c = 0x49afc7;
    piVar2 = (int *)FUN_004ce990();
    if (*piVar2 < 1) {
      FUN_00475c70();
      if (param_5 < 2) {
        local_3c = param_5;
      }
      else {
        local_3c = 1;
      }
      iStack_5c = 0;
      iStack_60 = param_5;
      uStack_64 = *(undefined4 *)(param_1 + 0x3cc + param_2 * 4);
      pvStack_68 = local_18[local_3c];
      uStack_6c = param_4;
      uStack_70 = local_30;
      puStack_74 = (undefined1 *)param_2;
      uStack_78 = 0x49b025;
      FUN_004cc4c0();
      puStack_74 = (undefined1 *)0x49b02c;
      puStack_74 = (undefined1 *)FUN_004cbb30();
      uStack_78 = 0x49b032;
      uVar3 = FUN_00530810();
      iStack_5c = 0x49b05c;
      puVar4 = (undefined4 *)FUN_004ce990();
      *puVar4 = uVar3;
    }
    iStack_5c = 0x49b083;
    piVar2 = (int *)FUN_004ce990();
    if (*piVar2 < 1) {
      puStack_74 = &DAT_007d0621;
      uStack_78 = 0x49b09e;
      basic_string<>();
      local_8 = 0;
      pcStack_90 = "This font was not generable.";
      uStack_94 = 0x49b0c0;
      basic_string<>();
      local_8 = CONCAT31(local_8._1_3_,1);
      pcStack_90 = (char *)param_2;
      uStack_94 = 0x49b0df;
      pbVar5 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               FUN_004cc4c0();
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
      basic_string<char,std::char_traits<char>,std::allocator<char>_>(abStack_a8,pbVar5);
      local_8 = 0xffffffff;
      FUN_0042bed0();
      pcVar6 = (char *)FUN_004cbb30();
      iStack_5c = param_2;
      iStack_60 = 0x49b120;
      this = (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)FUN_004cc4c0();
      iStack_5c = 0x49b127;
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=(this,pcVar6);
      iStack_5c = 0;
      iStack_60 = param_5;
      uStack_64 = *(undefined4 *)(param_1 + 0x3cc + param_2 * 4);
      pvStack_68 = local_18[param_5];
      uStack_6c = param_4;
      uStack_70 = local_30;
      puStack_74 = (undefined1 *)param_2;
      uStack_78 = 0x49b15f;
      FUN_004cc4c0();
      puStack_74 = (undefined1 *)0x49b166;
      puStack_74 = (undefined1 *)FUN_004cbb30();
      uStack_78 = 0x49b16c;
      uVar3 = FUN_00530810();
      iStack_5c = 0x49b196;
      puVar4 = (undefined4 *)FUN_004ce990();
      *puVar4 = uVar3;
    }
    *(int *)(param_1 + 0x3c8) = *(int *)(param_1 + 0x3c8) + 1;
  }
  ExceptionList = local_18[2];
  return;
}

