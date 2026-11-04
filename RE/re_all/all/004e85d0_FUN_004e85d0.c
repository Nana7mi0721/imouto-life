
undefined4 __thiscall
FUN_004e85d0(int param_1,undefined4 param_2,char param_3,int param_4,undefined4 param_5)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  char *pcVar5;
  int *piVar6;
  undefined1 *puVar7;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_5c [28];
  undefined1 local_40 [40];
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007b11f8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  iVar2 = FUN_004eb1a0();
  if (iVar2 - 1U <= *(uint *)(param_1 + 8)) {
    basic_string<>("map/set<T> too long");
    local_8 = 0;
    FID_conflict_length_error(local_40,local_5c);
    __CxxThrowException_8(local_40,&DAT_00845c30);
  }
  local_14 = FUN_004eb460(*(undefined4 *)(param_1 + 4),param_4,*(undefined4 *)(param_1 + 4),param_5,
                          0);
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
  if (param_4 == *(int *)(param_1 + 4)) {
    piVar3 = (int *)FUN_004e1fc0();
    *piVar3 = local_14;
    piVar3 = (int *)FUN_004e1f00();
    *piVar3 = local_14;
    piVar3 = (int *)FUN_004e1fa0();
    *piVar3 = local_14;
  }
  else if (param_3 == '\0') {
    piVar3 = (int *)FUN_004d6880(param_4);
    *piVar3 = local_14;
    piVar3 = (int *)FUN_004e1fa0();
    if (param_4 == *piVar3) {
      piVar3 = (int *)FUN_004e1fa0();
      *piVar3 = local_14;
    }
  }
  else {
    piVar3 = (int *)FUN_004e8ab0(param_4);
    *piVar3 = local_14;
    piVar3 = (int *)FUN_004e1f00();
    if (param_4 == *piVar3) {
      piVar3 = (int *)FUN_004e1f00();
      *piVar3 = local_14;
    }
  }
  local_18 = local_14;
  while( true ) {
    puVar4 = (undefined4 *)FUN_004d6870(local_18);
    pcVar5 = (char *)FUN_004d6850(*puVar4);
    if (*pcVar5 != '\0') break;
    piVar3 = (int *)FUN_004d6870(local_18);
    puVar4 = (undefined4 *)FUN_004d6870(local_18);
    puVar4 = (undefined4 *)FUN_004d6870(*puVar4);
    piVar6 = (int *)FUN_004e8ab0(*puVar4);
    if (*piVar3 == *piVar6) {
      puVar4 = (undefined4 *)FUN_004d6870(local_18);
      puVar4 = (undefined4 *)FUN_004d6870(*puVar4);
      puVar4 = (undefined4 *)FUN_004d6880(*puVar4);
      uVar1 = *puVar4;
      pcVar5 = (char *)FUN_004d6850(uVar1);
      if (*pcVar5 == '\0') {
        puVar4 = (undefined4 *)FUN_004d6870(local_18);
        puVar7 = (undefined1 *)FUN_004d6850(*puVar4);
        *puVar7 = 1;
        puVar7 = (undefined1 *)FUN_004d6850(uVar1);
        *puVar7 = 1;
        puVar4 = (undefined4 *)FUN_004d6870(local_18);
        puVar4 = (undefined4 *)FUN_004d6870(*puVar4);
        puVar7 = (undefined1 *)FUN_004d6850(*puVar4);
        *puVar7 = 0;
        puVar4 = (undefined4 *)FUN_004d6870(local_18);
        piVar3 = (int *)FUN_004d6870(*puVar4);
        local_18 = *piVar3;
      }
      else {
        puVar4 = (undefined4 *)FUN_004d6870(local_18);
        piVar3 = (int *)FUN_004d6880(*puVar4);
        if (local_18 == *piVar3) {
          piVar3 = (int *)FUN_004d6870(local_18);
          local_18 = *piVar3;
          FUN_004d7600(local_18);
        }
        puVar4 = (undefined4 *)FUN_004d6870(local_18);
        puVar7 = (undefined1 *)FUN_004d6850(*puVar4);
        *puVar7 = 1;
        puVar4 = (undefined4 *)FUN_004d6870(local_18);
        puVar4 = (undefined4 *)FUN_004d6870(*puVar4);
        puVar7 = (undefined1 *)FUN_004d6850(*puVar4);
        *puVar7 = 0;
        puVar4 = (undefined4 *)FUN_004d6870(local_18);
        puVar4 = (undefined4 *)FUN_004d6870(*puVar4);
        FUN_004eb1c0(*puVar4);
      }
    }
    else {
      puVar4 = (undefined4 *)FUN_004d6870(local_18);
      puVar4 = (undefined4 *)FUN_004d6870(*puVar4);
      puVar4 = (undefined4 *)FUN_004e8ab0(*puVar4);
      uVar1 = *puVar4;
      pcVar5 = (char *)FUN_004d6850(uVar1);
      if (*pcVar5 == '\0') {
        puVar4 = (undefined4 *)FUN_004d6870(local_18);
        puVar7 = (undefined1 *)FUN_004d6850(*puVar4);
        *puVar7 = 1;
        puVar7 = (undefined1 *)FUN_004d6850(uVar1);
        *puVar7 = 1;
        puVar4 = (undefined4 *)FUN_004d6870(local_18);
        puVar4 = (undefined4 *)FUN_004d6870(*puVar4);
        puVar7 = (undefined1 *)FUN_004d6850(*puVar4);
        *puVar7 = 0;
        puVar4 = (undefined4 *)FUN_004d6870(local_18);
        piVar3 = (int *)FUN_004d6870(*puVar4);
        local_18 = *piVar3;
      }
      else {
        puVar4 = (undefined4 *)FUN_004d6870(local_18);
        piVar3 = (int *)FUN_004e8ab0(*puVar4);
        if (local_18 == *piVar3) {
          piVar3 = (int *)FUN_004d6870(local_18);
          local_18 = *piVar3;
          FUN_004eb1c0(local_18);
        }
        puVar4 = (undefined4 *)FUN_004d6870(local_18);
        puVar7 = (undefined1 *)FUN_004d6850(*puVar4);
        *puVar7 = 1;
        puVar4 = (undefined4 *)FUN_004d6870(local_18);
        puVar4 = (undefined4 *)FUN_004d6870(*puVar4);
        puVar7 = (undefined1 *)FUN_004d6850(*puVar4);
        *puVar7 = 0;
        puVar4 = (undefined4 *)FUN_004d6870(local_18);
        puVar4 = (undefined4 *)FUN_004d6870(*puVar4);
        FUN_004d7600(*puVar4);
      }
    }
  }
  puVar4 = (undefined4 *)FUN_004e1fc0();
  puVar7 = (undefined1 *)FUN_004d6850(*puVar4);
  *puVar7 = 1;
  FUN_004e92a0(local_14);
  ExceptionList = local_10;
  return param_2;
}

