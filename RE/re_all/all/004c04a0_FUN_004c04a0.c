
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __fastcall FUN_004c04a0(int param_1)

{
  char cVar1;
  undefined4 *puVar2;
  char *pcVar3;
  uint uVar4;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *pbVar5;
  undefined4 *puVar6;
  int *piVar7;
  undefined *puStack_50c;
  undefined4 uStack_508;
  undefined *puStack_504;
  int local_43c;
  int local_438;
  uint local_434;
  char local_430 [516];
  int local_22c;
  int local_228;
  int local_224;
  char local_220 [516];
  undefined4 local_1c;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007b0bac;
  local_10 = ExceptionList;
  local_1c = DAT_0084b484;
  ExceptionList = &local_10;
  if (DAT_00a18c84 == 0) {
    ExceptionList = &local_10;
    FUN_004cb840();
    for (local_14 = 0; local_14 < 0xf; local_14 = local_14 + 1) {
      FUN_004cb840();
    }
    cVar1 = operator!=<>();
    if (cVar1 != '\0') {
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
      basic_string<char,std::char_traits<char>,std::allocator<char>_>
                ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)&puStack_50c,
                 (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                 (param_1 + 4));
      FUN_00422450();
      puVar2 = (undefined4 *)FUN_004cc680();
      *(undefined4 *)(param_1 + 0x1c4) = *puVar2;
      FUN_004cde80();
      FUN_004ce990();
      FUN_00515880();
      if (local_18 != DAT_0084b264 * 8) {
        puStack_50c = &DAT_007d1e50;
        basic_string<>();
        puStack_50c = (undefined *)0x4c0614;
        pcVar3 = (char *)FUN_00401c50();
        _sprintf(local_220,pcVar3);
        puStack_504 = &DAT_007d1e0c;
        uStack_508 = 0x4c0648;
        basic_string<>();
        puStack_504 = (undefined *)0x4c0653;
        puStack_504 = (undefined *)FUN_00401c50();
        uStack_508 = 0x4c0673;
        basic_string<>();
        local_8 = 0;
        basic_string<>();
        FUN_00401c50();
        basic_string<>();
        local_8 = CONCAT31(local_8._1_3_,1);
        basic_string<>(local_220);
        local_8 = 0xffffffff;
        FUN_0042bed0();
      }
    }
    for (local_224 = 0; local_224 < 0xf; local_224 = local_224 + 1) {
      cVar1 = operator!=<>();
      if (cVar1 == '\0') {
        *(undefined1 *)(param_1 + local_224 + 0x250) = 0;
      }
      else {
        *(undefined1 *)(param_1 + local_224 + 0x250) = 1;
        std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
        basic_string<char,std::char_traits<char>,std::allocator<char>_>
                  ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)&puStack_50c,
                   (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                   (param_1 + 0x20 + local_224 * 0x1c));
        FUN_00422450();
        puVar2 = (undefined4 *)FUN_004cc680();
        *(undefined4 *)(param_1 + 0x1c8 + local_224 * 4) = *puVar2;
        FUN_004cde80();
        FUN_004ce990();
        FUN_00515880();
        *(int *)(param_1 + 0x204 + local_224 * 4) = local_228 / DAT_0084b264;
        cVar1 = operator!=<>();
        if ((cVar1 != '\0') && ((local_228 < DAT_0084b264 || (local_22c < DAT_0084b264 * 5)))) {
          FUN_004cbb30();
          basic_string<>();
          pcVar3 = (char *)FUN_00401c50();
          puStack_504 = (undefined *)0x4c0927;
          _sprintf(local_430,pcVar3);
          puStack_504 = &DAT_007d1e0c;
          uStack_508 = 0x4c093f;
          basic_string<>();
          puStack_504 = (undefined *)0x4c094a;
          puStack_504 = (undefined *)FUN_00401c50();
          uStack_508 = 0x4c096a;
          basic_string<>();
          local_8 = 2;
          basic_string<>();
          FUN_00401c50();
          basic_string<>();
          local_8 = CONCAT31(local_8._1_3_,3);
          basic_string<>(local_430);
          local_8 = 0xffffffff;
          FUN_0042bed0();
        }
      }
    }
  }
  if (DAT_00a18c84 == 1) {
    FUN_004ce950();
    FUN_004cc430();
    FUN_004ce970();
    FUN_004ce950();
    FUN_004cc430();
    FUN_004ce970();
    for (local_434 = 0; uVar4 = FUN_004cc430(), local_434 < uVar4; local_434 = local_434 + 1) {
      FUN_004cc4c0();
      cVar1 = FUN_004cbb70();
      if (cVar1 == '\0') {
        pbVar5 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                 FUN_004cc4c0();
        std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
        basic_string<char,std::char_traits<char>,std::allocator<char>_>
                  ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)&puStack_50c,
                   pbVar5);
        FUN_00422450();
        FUN_004cc4c0();
        FUN_004cc680();
        FUN_004cde80();
        puVar2 = (undefined4 *)FUN_004ce990();
        puVar6 = (undefined4 *)FUN_004ce990();
        *puVar6 = *puVar2;
        FUN_004ce990();
        FUN_00515880();
        piVar7 = (int *)FUN_004ce990();
        *piVar7 = local_438 * 10000 + local_43c;
      }
    }
  }
  ExceptionList = local_10;
  return;
}

