
undefined4 FUN_0065a850(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  undefined8 uVar10;
  longlong lVar11;
  char *pcVar12;
  char *pcVar13;
  uint uStack_18;
  int iStack_14;
  uint uStack_10;
  int iStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  puVar2 = param_1;
  uVar7 = param_1[4];
  iVar3 = param_1[5];
  if (uVar7 != 0 || iVar3 != 0) {
    if ((param_1[3] & 0x80000) == 0) {
      uVar9 = param_1[0x6b];
      puVar1 = param_1 + 0x6b;
      if ((uVar9 != uVar7) || (iVar3 != 0)) {
        do {
          uVar10 = (*(code *)puVar2[0xa0])(puVar2[0x9d],uVar9,0,0);
          if (((uint)uVar10 != uVar9) ||
             (((int)((ulonglong)uVar10 >> 0x20) != 0 ||
              (iVar3 = (*(code *)puVar2[0x9e])(puVar2[0x9d],&param_1,2), iVar3 != 2)))) {
            FUN_006512e0(puVar2[0x9d],"TIFFRewriteDirectory",
                         s_Error_fetching_directory_count_00a06994);
            return 0;
          }
          if ((*(byte *)(puVar2 + 3) & 0x80) != 0) {
            FUN_0065a5f0(&param_1);
          }
          (*(code *)puVar2[0xa0])(puVar2[0x9d],uVar9 + 2 + ((uint)param_1 & 0xffff) * 0xc,0,0);
          iVar3 = (*(code *)puVar2[0x9e])(puVar2[0x9d],&uStack_18,4);
          if (iVar3 != 4) {
LAB_0065ab97:
            FUN_006512e0(puVar2[0x9d],"TIFFRewriteDirectory",
                         s_Error_fetching_directory_link_00a069b4);
            return 0;
          }
          if ((*(byte *)(puVar2 + 3) & 0x80) != 0) {
            FUN_0065a600(&uStack_18);
          }
          if ((uStack_18 == puVar2[4]) && (puVar2[5] == 0)) {
            uStack_10 = 0;
            (*(code *)puVar2[0xa0])(puVar2[0x9d],uVar9 + 2 + ((uint)param_1 & 0xffff) * 0xc,0,0);
            iVar3 = (*(code *)puVar2[0x9f])(puVar2[0x9d],&uStack_10,4);
            if (iVar3 != 4) {
              FUN_006512e0(puVar2[0x9d],"TIFFRewriteDirectory",
                           s_Error_writing_directory_link_00a069d4);
              return 0;
            }
            puVar2[4] = 0;
            puVar2[5] = 0;
            goto LAB_0065a9fe;
          }
          uVar9 = uStack_18;
        } while( true );
      }
      param_1[4] = 0;
      *puVar1 = 0;
      param_1[5] = 0;
      (*(code *)param_1[0xa0])(param_1[0x9d],4,0,0);
      iVar3 = (*(code *)puVar2[0x9f])(puVar2[0x9d],puVar1,4);
      if (iVar3 != 4) {
        pcVar12 = (char *)*puVar2;
        pcVar13 = s_Error_updating_TIFF_header_00a0a664;
LAB_0065ac10:
        FUN_006512e0(puVar2[0x9d],pcVar12,pcVar13);
        return 0;
      }
    }
    else {
      uVar9 = param_1[0x6c];
      iVar8 = param_1[0x6d];
      puVar1 = param_1 + 0x6c;
      if ((uVar9 != uVar7) || (iVar8 != iVar3)) {
        while( true ) {
          lVar11 = (*(code *)puVar2[0xa0])(puVar2[0x9d],uVar9,iVar8,0);
          if ((lVar11 != CONCAT44(iVar8,uVar9)) ||
             (iVar3 = (*(code *)puVar2[0x9e])(puVar2[0x9d],&uStack_10,8), iVar3 != 8)) {
            FUN_006512e0(puVar2[0x9d],"TIFFRewriteDirectory",
                         s_Error_fetching_directory_count_00a06994);
            return 0;
          }
          if ((*(byte *)(puVar2 + 3) & 0x80) != 0) {
            FUN_0065a620(&uStack_10);
          }
          uVar7 = uStack_10;
          if ((iStack_c != 0) || (0xffff < uStack_10)) {
            pcVar13 = s_Sanity_check_on_tag_count_failed_00a0a62c;
            pcVar12 = "TIFFRewriteDirectory";
            goto LAB_0065ab7e;
          }
          uVar5 = (uStack_10 & 0xffff) * 0x14;
          uVar6 = uVar5 + uVar9;
          (*(code *)puVar2[0xa0])
                    (puVar2[0x9d],uVar6 + 8,
                     iVar8 + (uint)CARRY4(uVar5,uVar9) + (uint)(0xfffffff7 < uVar6),0);
          iVar3 = (*(code *)puVar2[0x9e])(puVar2[0x9d],&uStack_18,8);
          if (iVar3 != 8) goto LAB_0065ab97;
          if ((*(byte *)(puVar2 + 3) & 0x80) != 0) {
            FUN_0065a620(&uStack_18);
          }
          if ((uStack_18 == puVar2[4]) && (iStack_14 == puVar2[5])) break;
          iVar8 = iStack_14;
          uVar9 = uStack_18;
        }
        uStack_8 = 0;
        uStack_4 = 0;
        uVar7 = (uVar7 & 0xffff) * 0x14;
        uVar5 = uVar7 + uVar9;
        (*(code *)puVar2[0xa0])
                  (puVar2[0x9d],uVar5 + 8,
                   iVar8 + (uint)CARRY4(uVar7,uVar9) + (uint)(0xfffffff7 < uVar5),0);
        iVar3 = (*(code *)puVar2[0x9f])(puVar2[0x9d],&uStack_8,8);
        if (iVar3 == 8) {
          puVar2[4] = 0;
          puVar2[5] = 0;
          uVar4 = FUN_0065a830(puVar2);
          return uVar4;
        }
        pcVar13 = s_Error_writing_directory_link_00a069d4;
        pcVar12 = "TIFFRewriteDirectory";
        goto LAB_0065ac10;
      }
      *puVar1 = 0;
      param_1[4] = 0;
      param_1[0x6d] = 0;
      param_1[5] = 0;
      (*(code *)param_1[0xa0])(param_1[0x9d],8,0,0);
      iVar3 = (*(code *)puVar2[0x9f])(puVar2[0x9d],puVar1,8);
      if (iVar3 != 8) {
        pcVar12 = (char *)*puVar2;
        pcVar13 = s_Error_updating_TIFF_header_00a0a664;
LAB_0065ab7e:
        FUN_006512e0(puVar2[0x9d],pcVar12,pcVar13);
        return 0;
      }
    }
  }
LAB_0065a9fe:
  uVar4 = FUN_0065a830(puVar2);
  return uVar4;
}

