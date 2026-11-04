
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004c6350(int param_1,char param_2,int param_3)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  char *pcVar4;
  undefined4 uVar5;
  uint uVar6;
  int local_19c;
  int local_198;
  int local_178;
  int local_174;
  char local_168 [200];
  undefined4 local_a0;
  int local_9c;
  uint local_98;
  int local_94;
  int local_90;
  int local_8c;
  int local_88;
  int local_84;
  int local_80;
  undefined4 local_7c;
  int local_78;
  int local_74;
  int local_70;
  int local_6c;
  int local_68 [9];
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34 [9];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007b0d36;
  local_10 = ExceptionList;
  local_a0 = DAT_0084b484;
  if (DAT_00a18c84 == 1) {
    ExceptionList = &local_10;
    FUN_004c74e0();
  }
  else {
    ExceptionList = &local_10;
    cVar1 = operator!=<>();
    if (cVar1 != '\0') {
      FUN_004c03f0();
    }
    if (*(int *)(param_1 + 0x1c4) != -1) {
      FUN_004cde80();
      local_70 = FUN_004ce080();
      if (param_2 == '\0') {
        *(int *)(param_1 + 0x9eb4) = *(int *)(param_1 + 0x9eb4) - _DAT_00a180f8;
        *(int *)(param_1 + 0x9eb8) = *(int *)(param_1 + 0x9eb8) - _DAT_00a180fc;
      }
      *(int *)(param_1 + 0x260) = DAT_00a180f0 / 0x14;
      FUN_005160d0();
      if (param_2 == '\0') {
        _memset((void *)(param_1 + 0x264),-1,40000);
      }
      local_34[8] = (DAT_0084b248 * 100 * DAT_00a18174) / 100;
      local_7c = 0xffffffff;
      local_78 = -1;
      local_74 = (int)*DAT_00a1671c / DAT_0084b264 + 1 +
                 (uint)(0 < (int)*DAT_00a1671c % DAT_0084b264);
      if (0 < (*DAT_00a1671c + 0x20) - DAT_0084b264 * local_74) {
        local_74 = local_74 + 1;
      }
      local_80 = (int)*DAT_00a16718 / DAT_0084b264 + 1;
      if (0 < (*DAT_00a16718 + 0x20) - DAT_0084b264 * local_80) {
        local_80 = (int)*DAT_00a16718 / DAT_0084b264 + 2;
      }
      for (local_84 = -1; local_84 < local_74; local_84 = local_84 + 1) {
        if (param_2 == '\x01') {
          local_84 = param_3 - *(int *)(param_1 + 0x9eb8) / DAT_0084b264;
          if (local_74 < local_84) {
            ExceptionList = local_10;
            return;
          }
          if (DAT_00a180f5 == '\0') {
            if (*(int *)(param_1 + 0x9eb8) / DAT_0084b264 + local_84 < 0) {
              ExceptionList = local_10;
              return;
            }
            iVar2 = FUN_0047a4b0();
            if (iVar2 <= *(int *)(param_1 + 0x9eb8) / DAT_0084b264 + local_84) {
              ExceptionList = local_10;
              return;
            }
          }
LAB_004c6648:
          for (local_88 = local_78; local_88 < local_80; local_88 = local_88 + 1) {
            local_8c = *(int *)(param_1 + (local_84 + 2) * 400 + 0x268 + local_88 * 4);
            while (local_8c = local_8c + 1, local_8c < 3) {
              if ((DAT_00a180f4 != '\0') ||
                 ((-1 < *(int *)(param_1 + 0x9eb4) / DAT_0084b264 + local_88 &&
                  (iVar2 = FUN_0047a490(),
                  *(int *)(param_1 + 0x9eb4) / DAT_0084b264 + local_88 < iVar2)))) {
                FUN_0047a4b0();
                FUN_0047a4b0();
                FUN_0047a490();
                FUN_0047a490();
                FUN_004cd3a0();
                FUN_004cde80();
                piVar3 = (int *)FUN_004ce990();
                local_68[8] = *piVar3;
                if (local_68[8] < 100000) {
                  if (local_68[8] < 0) {
                    basic_string<>();
                    pcVar4 = (char *)FUN_00401c50();
                    _sprintf(local_168,pcVar4);
                    basic_string<>();
                    local_8 = 0;
                    basic_string<>();
                    FUN_00401c50();
                    basic_string<>();
                    local_8 = CONCAT31(local_8._1_3_,1);
                    basic_string<>(&DAT_007d1ec0);
                    uVar5 = FUN_00401c50();
                    basic_string<>(uVar5);
                    local_8 = 0xffffffff;
                    FUN_0042bed0();
                    /* WARNING: Subroutine does not return */
                    _exit(1);
                  }
                  if (local_68[8] < local_70) {
                    if (param_2 < '\x01') {
                      pcVar4 = (char *)FUN_004cd7c0();
                      cVar1 = *pcVar4;
                    }
                    else {
                      pcVar4 = (char *)FUN_004cd7c0();
                      cVar1 = *pcVar4;
                    }
                    if (param_2 < cVar1) break;
                    *(int *)(param_1 + (local_84 + 2) * 400 + 0x268 + local_88 * 4) = local_8c;
                    if ((DAT_0084b248 == 1) && (DAT_00a18174 == 100)) {
                      FUN_004cde80();
                      FUN_004ce990();
                      FUN_0051e930();
                    }
                    else {
                      for (local_174 = 0; local_174 < 1; local_174 = local_174 + 1) {
                        local_68[local_174 * 2] =
                             (local_88 * DAT_0084b264 - *(int *)(param_1 + 0x9eb4) % DAT_0084b264) *
                             DAT_0084b248;
                        local_34[local_174 * 2] =
                             (local_84 * DAT_0084b264 - *(int *)(param_1 + 0x9eb8) % DAT_0084b264) *
                             DAT_0084b248;
                        local_68[local_174 * 2 + 1] =
                             ((local_88 * DAT_0084b264 - *(int *)(param_1 + 0x9eb4) % DAT_0084b264)
                             + DAT_0084b264) * DAT_0084b248;
                        local_34[local_174 * 2 + 1] =
                             ((local_84 * DAT_0084b264 - *(int *)(param_1 + 0x9eb8) % DAT_0084b264)
                             + DAT_0084b264) * DAT_0084b248;
                        for (local_178 = 0; local_178 < 2; local_178 = local_178 + 1) {
                          local_68[local_174 * 2 + local_178] =
                               ((local_68[local_174 * 2 + local_178] - DAT_00a1816c * DAT_0084b248)
                               * (DAT_00a18174 + -100)) / 100 + local_68[local_174 * 2 + local_178];
                          local_34[local_174 * 2 + local_178] =
                               ((local_34[local_174 * 2 + local_178] - DAT_00a18170 * DAT_0084b248)
                               * (DAT_00a18174 + -100)) / 100 + local_34[local_174 * 2 + local_178];
                        }
                      }
                      FUN_004cde80();
                      FUN_004ce990();
                      FUN_0051f060();
                    }
                  }
                }
                else {
                  if (param_2 < '\x01') {
                    pcVar4 = (char *)FUN_004cd7c0();
                    cVar1 = *pcVar4;
                  }
                  else {
                    pcVar4 = (char *)FUN_004cd7c0();
                    cVar1 = *pcVar4;
                  }
                  if (param_2 < cVar1) break;
                  if (((local_68[8] < 0x19f0a1) && (local_68[8] / 100000 != 1)) &&
                     (*(char *)(param_1 + 0x24e + local_68[8] / 100000) != '\0')) {
                    *(int *)(param_1 + (local_84 + 2) * 400 + 0x268 + local_88 * 4) = local_8c;
                    local_40 = local_68[8] / 100000 + -2;
                    local_3c = (*(int *)(param_1 + 0x260) % *(int *)(param_1 + 0x204 + local_40 * 4)
                               ) * 2 + 1 +
                               ((local_68[8] % 100000) / 1000) * 2 *
                               *(int *)(param_1 + 0x204 + local_40 * 4) * 2;
                    local_44 = (*(int *)(param_1 + 0x260) % *(int *)(param_1 + 0x204 + local_40 * 4)
                               ) * 2 + 2 +
                               ((local_68[8] % 1000) / 100) * 2 *
                               *(int *)(param_1 + 0x204 + local_40 * 4) * 2;
                    local_6c = (*(int *)(param_1 + 0x260) % *(int *)(param_1 + 0x204 + local_40 * 4)
                               ) * 2 + 1 +
                               (((local_68[8] % 100) / 10) * 2 + 1) *
                               *(int *)(param_1 + 0x204 + local_40 * 4) * 2;
                    local_38 = (*(int *)(param_1 + 0x260) % *(int *)(param_1 + 0x204 + local_40 * 4)
                               ) * 2 + 2 +
                               ((local_68[8] % 10) * 2 + 1) *
                               *(int *)(param_1 + 0x204 + local_40 * 4) * 2;
                    if ((DAT_0084b248 == 1) && (DAT_00a18174 == 100)) {
                      FUN_004cde80();
                      FUN_004ce990();
                      FUN_0051e930();
                      FUN_004cde80();
                      FUN_004ce990();
                      FUN_0051e930();
                      FUN_004cde80();
                      FUN_004ce990();
                      FUN_0051e930();
                      FUN_004cde80();
                      FUN_004ce990();
                      FUN_0051e930();
                    }
                    else {
                      local_94 = 0;
                      local_90 = 0;
                      for (local_98 = 0; (int)local_98 < 4; local_98 = local_98 + 1) {
                        uVar6 = local_98 & 0x80000001;
                        if ((int)uVar6 < 0) {
                          uVar6 = (uVar6 - 1 | 0xfffffffe) + 1;
                        }
                        if (uVar6 == 0) {
                          local_198 = 0;
                        }
                        else {
                          local_198 = DAT_0084b264 / 2;
                        }
                        local_94 = local_198;
                        if ((int)local_98 < 2) {
                          local_19c = 0;
                        }
                        else {
                          local_19c = DAT_0084b264 / 2;
                        }
                        local_90 = local_19c;
                        local_68[local_98 * 2] =
                             ((local_88 * DAT_0084b264 - *(int *)(param_1 + 0x9eb4) % DAT_0084b264)
                             + local_198) * DAT_0084b248;
                        local_34[local_98 * 2] =
                             ((local_84 * DAT_0084b264 - *(int *)(param_1 + 0x9eb8) % DAT_0084b264)
                             + local_19c) * DAT_0084b248;
                        local_68[local_98 * 2 + 1] =
                             ((local_88 * DAT_0084b264 - *(int *)(param_1 + 0x9eb4) % DAT_0084b264)
                              + local_198 + DAT_0084b264 / 2) * DAT_0084b248;
                        local_34[local_98 * 2 + 1] =
                             ((local_84 * DAT_0084b264 - *(int *)(param_1 + 0x9eb8) % DAT_0084b264)
                              + local_19c + DAT_0084b264 / 2) * DAT_0084b248;
                        for (local_9c = 0; local_9c < 2; local_9c = local_9c + 1) {
                          local_68[local_98 * 2 + local_9c] =
                               ((local_68[local_98 * 2 + local_9c] - DAT_00a1816c * DAT_0084b248) *
                               (DAT_00a18174 + -100)) / 100 + local_68[local_98 * 2 + local_9c];
                          local_34[local_98 * 2 + local_9c] =
                               ((local_34[local_98 * 2 + local_9c] - DAT_00a18170 * DAT_0084b248) *
                               (DAT_00a18174 + -100)) / 100 + local_34[local_98 * 2 + local_9c];
                        }
                      }
                      FUN_004cde80();
                      FUN_004ce990();
                      FUN_0051f060();
                      FUN_004cde80();
                      FUN_004ce990();
                      FUN_0051f060();
                      FUN_004cde80();
                      FUN_004ce990();
                      FUN_0051f060();
                      FUN_004cde80();
                      FUN_004ce990();
                      FUN_0051f060();
                    }
                  }
                }
              }
            }
          }
          if (param_2 == '\x01') {
            ExceptionList = local_10;
            return;
          }
        }
        else if ((DAT_00a180f5 != '\0') ||
                ((-1 < *(int *)(param_1 + 0x9eb8) / DAT_0084b264 + local_84 &&
                 (iVar2 = FUN_0047a4b0(),
                 *(int *)(param_1 + 0x9eb8) / DAT_0084b264 + local_84 < iVar2)))) goto LAB_004c6648;
      }
    }
  }
  ExceptionList = local_10;
  return;
}

