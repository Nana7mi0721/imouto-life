
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __thiscall
FUN_004712f0(int param_1,undefined1 *param_2,undefined1 *param_3,undefined1 *param_4,
            undefined1 *param_5,undefined1 *param_6,undefined1 *param_7,undefined1 *param_8,
            undefined1 *param_9)

{
  uint uVar1;
  undefined4 uVar2;
  byte *pbVar3;
  char *pcVar4;
  int iVar5;
  int *piVar6;
  uint *puVar7;
  char local_1a8 [200];
  char local_e0 [204];
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007ae97c;
  local_10 = ExceptionList;
  local_14 = DAT_0084b484;
  ExceptionList = &local_10;
  *param_2 = 0;
  *param_3 = 0;
  *param_4 = 0;
  *param_5 = 0;
  *param_6 = 0;
  *param_7 = 0;
  *param_8 = 0;
  *param_9 = 0;
LAB_0047134d:
  do {
    uVar1 = FUN_004cd730();
    if (uVar1 <= *(uint *)(param_1 + 0x2c)) {
      basic_string<>();
      local_8 = 0;
      basic_string<>();
      local_8 = CONCAT31(local_8._1_3_,1);
      basic_string<>(&DAT_007d0794);
      uVar2 = FUN_00401c50();
      basic_string<>(uVar2);
      local_8 = 0xffffffff;
      FUN_0042bed0();
      DAT_00a117ad = 1;
LAB_00471772:
      *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + 1;
      ExceptionList = local_10;
      return;
    }
    pbVar3 = (byte *)FUN_004cd7c0();
    if (0xf9 < *pbVar3) {
      pcVar4 = (char *)FUN_004cd7c0();
      if (*pcVar4 == -6) {
        FUN_004174a0();
        basic_string<>();
        pcVar4 = (char *)FUN_00401c50();
        _sprintf(local_e0,pcVar4);
      }
      pcVar4 = (char *)FUN_004cd7c0();
      if ((*pcVar4 == -5) && (9 < *(uint *)(param_1 + 0x2c))) {
        iVar5 = FUN_004174a0();
        piVar6 = (int *)FUN_004ce990();
        if (iVar5 != *piVar6) {
          FUN_004174a0();
          FUN_004ce990();
          basic_string<>();
          pcVar4 = (char *)FUN_00401c50();
          _sprintf(local_1a8,pcVar4);
          basic_string<>();
          local_8 = 2;
          basic_string<>();
          local_8 = CONCAT31(local_8._1_3_,3);
          basic_string<>(local_1a8);
          local_8 = 0xffffffff;
          FUN_0042bed0();
        }
      }
      *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) + 1;
      goto LAB_0047134d;
    }
    pcVar4 = (char *)FUN_004cd7c0();
    if (*pcVar4 != '\0') {
      puVar7 = (uint *)FUN_004ce990();
      uVar1 = *puVar7;
      if (uVar1 != 0) {
        *param_2 = (uVar1 & 1) != 0;
        *param_3 = (uVar1 & 2) != 0;
        *param_4 = (uVar1 & 4) != 0;
        *param_5 = (uVar1 & 8) != 0;
        *param_6 = (uVar1 & 0x10) != 0;
        *param_7 = (uVar1 & 0x20) != 0;
        *param_8 = (uVar1 & 0x40) != 0;
        *param_9 = (uVar1 & 0x80) != 0;
      }
      pcVar4 = (char *)FUN_004cd7c0();
      *pcVar4 = *pcVar4 + -1;
      goto LAB_00471772;
    }
    *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) + 1;
  } while( true );
}

