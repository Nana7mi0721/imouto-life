
undefined4 * __thiscall FUN_004e7cd0(int param_1,undefined4 *param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  char *pcVar3;
  undefined4 *puVar4;
  int *piVar5;
  undefined4 *puVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  int local_70;
  int local_6c;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_64 [28];
  undefined1 local_48 [40];
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007b2088;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  uVar2 = FUN_004e9610();
  pcVar3 = (char *)FUN_004d6860(uVar2);
  if (*pcVar3 != '\0') {
    basic_string<>("invalid map/set<T> iterator");
    local_8 = 0;
    FID_conflict_length_error(local_48,local_64);
    __CxxThrowException_8(local_48,&DAT_008452e0);
  }
  local_14 = FUN_004e9610();
  FUN_004e9530();
  local_1c = local_14;
  puVar4 = (undefined4 *)FUN_004e8ab0(local_14);
  pcVar3 = (char *)FUN_004d6860(*puVar4);
  if (*pcVar3 == '\0') {
    puVar4 = (undefined4 *)FUN_004d6880(local_1c);
    pcVar3 = (char *)FUN_004d6860(*puVar4);
    if (*pcVar3 == '\0') {
      local_1c = FUN_004e9610();
      piVar5 = (int *)FUN_004d6880(local_1c);
      local_18 = *piVar5;
    }
    else {
      piVar5 = (int *)FUN_004e8ab0(local_1c);
      local_18 = *piVar5;
    }
  }
  else {
    piVar5 = (int *)FUN_004d6880(local_1c);
    local_18 = *piVar5;
  }
  if (local_1c == local_14) {
    piVar5 = (int *)FUN_004d6870(local_14);
    local_20 = *piVar5;
    pcVar3 = (char *)FUN_004d6860(local_18);
    if (*pcVar3 == '\0') {
      piVar5 = (int *)FUN_004d6870(local_18);
      *piVar5 = local_20;
    }
    piVar5 = (int *)FUN_004e1fc0();
    if (*piVar5 == local_14) {
      piVar5 = (int *)FUN_004e1fc0();
      *piVar5 = local_18;
    }
    else {
      piVar5 = (int *)FUN_004e8ab0(local_20);
      if (*piVar5 == local_14) {
        piVar5 = (int *)FUN_004e8ab0(local_20);
        *piVar5 = local_18;
      }
      else {
        piVar5 = (int *)FUN_004d6880(local_20);
        *piVar5 = local_18;
      }
    }
    piVar5 = (int *)FUN_004e1f00();
    if (*piVar5 == local_14) {
      pcVar3 = (char *)FUN_004d6860(local_18);
      if (*pcVar3 == '\0') {
        local_6c = FUN_004e8a70(local_18);
      }
      else {
        local_6c = local_20;
      }
      piVar5 = (int *)FUN_004e1f00();
      *piVar5 = local_6c;
    }
    piVar5 = (int *)FUN_004e1fa0();
    if (*piVar5 == local_14) {
      pcVar3 = (char *)FUN_004d6860(local_18);
      if (*pcVar3 == '\0') {
        local_70 = FUN_004e8a30(local_18);
      }
      else {
        local_70 = local_20;
      }
      piVar5 = (int *)FUN_004e1fa0();
      *piVar5 = local_70;
    }
  }
  else {
    puVar4 = (undefined4 *)FUN_004e8ab0(local_14);
    piVar5 = (int *)FUN_004d6870(*puVar4);
    *piVar5 = local_1c;
    puVar4 = (undefined4 *)FUN_004e8ab0(local_14);
    puVar6 = (undefined4 *)FUN_004e8ab0(local_1c);
    *puVar6 = *puVar4;
    piVar5 = (int *)FUN_004d6880(local_14);
    if (local_1c == *piVar5) {
      local_20 = local_1c;
    }
    else {
      piVar5 = (int *)FUN_004d6870(local_1c);
      local_20 = *piVar5;
      pcVar3 = (char *)FUN_004d6860(local_18);
      if (*pcVar3 == '\0') {
        piVar5 = (int *)FUN_004d6870(local_18);
        *piVar5 = local_20;
      }
      piVar5 = (int *)FUN_004e8ab0(local_20);
      *piVar5 = local_18;
      puVar4 = (undefined4 *)FUN_004d6880(local_14);
      puVar6 = (undefined4 *)FUN_004d6880(local_1c);
      *puVar6 = *puVar4;
      puVar4 = (undefined4 *)FUN_004d6880(local_14);
      piVar5 = (int *)FUN_004d6870(*puVar4);
      *piVar5 = local_1c;
    }
    piVar5 = (int *)FUN_004e1fc0();
    if (*piVar5 == local_14) {
      piVar5 = (int *)FUN_004e1fc0();
      *piVar5 = local_1c;
    }
    else {
      puVar4 = (undefined4 *)FUN_004d6870(local_14);
      piVar5 = (int *)FUN_004e8ab0(*puVar4);
      if (*piVar5 == local_14) {
        puVar4 = (undefined4 *)FUN_004d6870(local_14);
        piVar5 = (int *)FUN_004e8ab0(*puVar4);
        *piVar5 = local_1c;
      }
      else {
        puVar4 = (undefined4 *)FUN_004d6870(local_14);
        piVar5 = (int *)FUN_004d6880(*puVar4);
        *piVar5 = local_1c;
      }
    }
    puVar4 = (undefined4 *)FUN_004d6870(local_14);
    puVar6 = (undefined4 *)FUN_004d6870(local_1c);
    *puVar6 = *puVar4;
    uVar2 = FUN_004d6850(local_14);
    uVar2 = FUN_004d6850(local_1c,uVar2);
    FUN_004ecbd0(uVar2);
  }
  pcVar3 = (char *)FUN_004d6850(local_14);
  if (*pcVar3 != '\x01') {
LAB_004e8428:
    FUN_004d7820(local_14);
    deallocate(local_14,1);
    if (*(int *)(param_1 + 8) != 0) {
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -1;
    }
    *param_2 = param_3;
    ExceptionList = local_10;
    return param_2;
  }
LAB_004e80ac:
  piVar5 = (int *)FUN_004e1fc0();
  if ((local_18 == *piVar5) || (pcVar3 = (char *)FUN_004d6850(local_18), *pcVar3 != '\x01'))
  goto LAB_004e8419;
  piVar5 = (int *)FUN_004e8ab0(local_20);
  if (local_18 == *piVar5) {
    piVar5 = (int *)FUN_004d6880(local_20);
    local_1c = *piVar5;
    pcVar3 = (char *)FUN_004d6850(local_1c);
    if (*pcVar3 == '\0') {
      puVar7 = (undefined1 *)FUN_004d6850(local_1c);
      *puVar7 = 1;
      puVar7 = (undefined1 *)FUN_004d6850(local_20);
      *puVar7 = 0;
      FUN_004d7600(local_20);
      piVar5 = (int *)FUN_004d6880(local_20);
      local_1c = *piVar5;
    }
    pcVar3 = (char *)FUN_004d6860(local_1c);
    iVar1 = local_20;
    if (*pcVar3 == '\0') {
      puVar4 = (undefined4 *)FUN_004e8ab0(local_1c);
      pcVar3 = (char *)FUN_004d6850(*puVar4);
      if (*pcVar3 == '\x01') {
        puVar4 = (undefined4 *)FUN_004d6880(local_1c);
        pcVar3 = (char *)FUN_004d6850(*puVar4);
        if (*pcVar3 == '\x01') {
          puVar7 = (undefined1 *)FUN_004d6850(local_1c);
          *puVar7 = 0;
          iVar1 = local_20;
          goto LAB_004e809b;
        }
      }
      puVar4 = (undefined4 *)FUN_004d6880(local_1c);
      pcVar3 = (char *)FUN_004d6850(*puVar4);
      if (*pcVar3 == '\x01') {
        puVar4 = (undefined4 *)FUN_004e8ab0(local_1c);
        puVar7 = (undefined1 *)FUN_004d6850(*puVar4);
        *puVar7 = 1;
        puVar7 = (undefined1 *)FUN_004d6850(local_1c);
        *puVar7 = 0;
        FUN_004eb1c0(local_1c);
        piVar5 = (int *)FUN_004d6880(local_20);
        local_1c = *piVar5;
      }
      puVar7 = (undefined1 *)FUN_004d6850(local_20);
      puVar8 = (undefined1 *)FUN_004d6850(local_1c);
      *puVar8 = *puVar7;
      puVar7 = (undefined1 *)FUN_004d6850(local_20);
      *puVar7 = 1;
      puVar4 = (undefined4 *)FUN_004d6880(local_1c);
      puVar7 = (undefined1 *)FUN_004d6850(*puVar4);
      *puVar7 = 1;
      FUN_004d7600(local_20);
LAB_004e8419:
      puVar7 = (undefined1 *)FUN_004d6850(local_18);
      *puVar7 = 1;
      goto LAB_004e8428;
    }
  }
  else {
    piVar5 = (int *)FUN_004e8ab0(local_20);
    local_1c = *piVar5;
    pcVar3 = (char *)FUN_004d6850(local_1c);
    if (*pcVar3 == '\0') {
      puVar7 = (undefined1 *)FUN_004d6850(local_1c);
      *puVar7 = 1;
      puVar7 = (undefined1 *)FUN_004d6850(local_20);
      *puVar7 = 0;
      FUN_004eb1c0(local_20);
      piVar5 = (int *)FUN_004e8ab0(local_20);
      local_1c = *piVar5;
    }
    pcVar3 = (char *)FUN_004d6860(local_1c);
    if (*pcVar3 == '\0') {
      puVar4 = (undefined4 *)FUN_004d6880(local_1c);
      pcVar3 = (char *)FUN_004d6850(*puVar4);
      if (*pcVar3 == '\x01') {
        puVar4 = (undefined4 *)FUN_004e8ab0(local_1c);
        pcVar3 = (char *)FUN_004d6850(*puVar4);
        if (*pcVar3 == '\x01') {
          puVar7 = (undefined1 *)FUN_004d6850(local_1c);
          *puVar7 = 0;
          local_18 = local_20;
          iVar1 = local_18;
          goto LAB_004e809b;
        }
      }
      puVar4 = (undefined4 *)FUN_004e8ab0(local_1c);
      pcVar3 = (char *)FUN_004d6850(*puVar4);
      if (*pcVar3 == '\x01') {
        puVar4 = (undefined4 *)FUN_004d6880(local_1c);
        puVar7 = (undefined1 *)FUN_004d6850(*puVar4);
        *puVar7 = 1;
        puVar7 = (undefined1 *)FUN_004d6850(local_1c);
        *puVar7 = 0;
        FUN_004d7600(local_1c);
        piVar5 = (int *)FUN_004e8ab0(local_20);
        local_1c = *piVar5;
      }
      puVar7 = (undefined1 *)FUN_004d6850(local_20);
      puVar8 = (undefined1 *)FUN_004d6850(local_1c);
      *puVar8 = *puVar7;
      puVar7 = (undefined1 *)FUN_004d6850(local_20);
      *puVar7 = 1;
      puVar4 = (undefined4 *)FUN_004e8ab0(local_1c);
      puVar7 = (undefined1 *)FUN_004d6850(*puVar4);
      *puVar7 = 1;
      FUN_004eb1c0(local_20);
      goto LAB_004e8419;
    }
    local_18 = local_20;
    iVar1 = local_18;
  }
LAB_004e809b:
  local_18 = iVar1;
  local_20 = local_18;
  piVar5 = (int *)FUN_004d6870(local_18);
  local_20 = *piVar5;
  goto LAB_004e80ac;
}

