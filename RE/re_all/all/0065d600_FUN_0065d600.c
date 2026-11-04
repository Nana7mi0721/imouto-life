
undefined4 FUN_0065d600(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  bool bVar8;
  longlong lVar9;
  undefined8 uVar10;
  uint uStack_18;
  int iStack_14;
  uint uStack_10;
  undefined4 uStack_c;
  uint uStack_8;
  int iStack_4;
  
  puVar1 = param_1;
  lVar9 = (*(code *)param_1[0xa0])(param_1[0x9d],0,0,2);
  puVar1[4] = (uint)(lVar9 + 1) & 0xfffffffe;
  uVar7 = puVar1[3];
  puVar1[5] = (int)((ulonglong)(lVar9 + 1) >> 0x20);
  if ((uVar7 & 0x2000) == 0) {
    uVar6 = puVar1[4];
    if ((uVar7 & 0x80000) == 0) {
      uStack_18 = uVar6;
      if ((uVar7 & 0x80) != 0) {
        FUN_0065a600(&uStack_18);
      }
      uVar7 = puVar1[0x6b];
      if (puVar1[0x6b] != 0) {
        while( true ) {
          uVar10 = (*(code *)puVar1[0xa0])(puVar1[0x9d],uVar7,0,0);
          if ((((uint)uVar10 != uVar7) || ((int)((ulonglong)uVar10 >> 0x20) != 0)) ||
             (iVar2 = (*(code *)puVar1[0x9e])(puVar1[0x9d],&param_1,2), iVar2 != 2)) {
            FUN_006512e0(puVar1[0x9d],"TIFFLinkDirectory",s_Error_fetching_directory_count_00a06994)
            ;
            return 0;
          }
          if ((*(byte *)(puVar1 + 3) & 0x80) != 0) {
            FUN_0065a5f0(&param_1);
          }
          (*(code *)puVar1[0xa0])(puVar1[0x9d],uVar7 + 2 + ((uint)param_1 & 0xffff) * 0xc,0,0);
          iVar2 = (*(code *)puVar1[0x9e])(puVar1[0x9d],&uStack_10,4);
          if (iVar2 != 4) break;
          if ((*(byte *)(puVar1 + 3) & 0x80) != 0) {
            FUN_0065a600(&uStack_10);
          }
          if (uStack_10 == 0) {
            (*(code *)puVar1[0xa0])(puVar1[0x9d],uVar7 + 2 + ((uint)param_1 & 0xffff) * 0xc,0,0);
            iVar2 = (*(code *)puVar1[0x9f])(puVar1[0x9d],&uStack_18,4);
            if (iVar2 == 4) {
              return 1;
            }
            FUN_006512e0(puVar1[0x9d],"TIFFLinkDirectory",s_Error_writing_directory_link_00a069d4);
            return 0;
          }
          uVar7 = uStack_10;
        }
LAB_0065daf7:
        FUN_006512e0(puVar1[0x9d],"TIFFLinkDirectory",s_Error_fetching_directory_link_00a069b4);
        return 0;
      }
      puVar1[0x6b] = puVar1[4];
      (*(code *)puVar1[0xa0])(puVar1[0x9d],4,0,0);
      iVar2 = (*(code *)puVar1[0x9f])(puVar1[0x9d],&uStack_18,4);
      if (iVar2 != 4) {
        FUN_006512e0(puVar1[0x9d],*puVar1,s_Error_writing_TIFF_header_00a06a34);
        return 0;
      }
    }
    else {
      uStack_c = puVar1[5];
      uStack_10 = uVar6;
      if ((uVar7 & 0x80) != 0) {
        FUN_0065a620(&uStack_10);
      }
      iVar2 = puVar1[0x6d];
      uVar7 = puVar1[0x6c];
      if (puVar1[0x6c] == 0 && puVar1[0x6d] == 0) {
        puVar1[0x6c] = puVar1[4];
        puVar1[0x6d] = puVar1[5];
        (*(code *)puVar1[0xa0])(puVar1[0x9d],8,0,0);
        iVar2 = (*(code *)puVar1[0x9f])(puVar1[0x9d],&uStack_10,8);
        if (iVar2 != 8) {
          FUN_006512e0(puVar1[0x9d],*puVar1,s_Error_writing_TIFF_header_00a06a34);
          return 0;
        }
      }
      else {
        while( true ) {
          lVar9 = (*(code *)puVar1[0xa0])(puVar1[0x9d],uVar7,iVar2,0);
          if ((lVar9 != CONCAT44(iVar2,uVar7)) ||
             (iVar3 = (*(code *)puVar1[0x9e])(puVar1[0x9d],&uStack_18,8), iVar3 != 8)) {
            FUN_006512e0(puVar1[0x9d],"TIFFLinkDirectory",s_Error_fetching_directory_count_00a06994)
            ;
            return 0;
          }
          if ((*(byte *)(puVar1 + 3) & 0x80) != 0) {
            FUN_0065a620(&uStack_18);
          }
          uVar6 = uStack_18;
          if ((iStack_14 != 0) || (0xffff < uStack_18)) {
            FUN_006512e0(puVar1[0x9d],"TIFFLinkDirectory",
                         s_Sanity_check_on_tag_count_failed_00a0a62c);
            return 0;
          }
          uVar4 = (uStack_18 & 0xffff) * 0x14;
          uVar5 = uVar4 + uVar7;
          (*(code *)puVar1[0xa0])
                    (puVar1[0x9d],uVar5 + 8,
                     iVar2 + (uint)CARRY4(uVar4,uVar7) + (uint)(0xfffffff7 < uVar5),0);
          iVar3 = (*(code *)puVar1[0x9e])(puVar1[0x9d],&uStack_8,8);
          if (iVar3 != 8) goto LAB_0065daf7;
          if ((*(byte *)(puVar1 + 3) & 0x80) != 0) {
            FUN_0065a620(&uStack_8);
          }
          if (uStack_8 == 0 && iStack_4 == 0) break;
          iVar2 = iStack_4;
          uVar7 = uStack_8;
        }
        uVar6 = (uVar6 & 0xffff) * 0x14;
        uVar4 = uVar6 + uVar7;
        (*(code *)puVar1[0xa0])
                  (puVar1[0x9d],uVar4 + 8,
                   iVar2 + (uint)CARRY4(uVar6,uVar7) + (uint)(0xfffffff7 < uVar4),0);
        iVar2 = (*(code *)puVar1[0x9f])(puVar1[0x9d],&uStack_10,8);
        if (iVar2 != 8) {
          FUN_006512e0(puVar1[0x9d],"TIFFLinkDirectory",s_Error_writing_directory_link_00a069d4);
          return 0;
        }
      }
    }
  }
  else {
    uStack_10 = puVar1[4];
    if ((uVar7 & 0x80000) == 0) {
      param_1 = (undefined4 *)uStack_10;
      if ((uVar7 & 0x80) != 0) {
        FUN_0065a600(&param_1);
      }
      (*(code *)puVar1[0xa0])(puVar1[0x9d],puVar1[0x78],puVar1[0x79],0);
      iVar2 = (*(code *)puVar1[0x9f])(puVar1[0x9d],&param_1,4);
      if (iVar2 != 4) {
        FUN_006512e0(puVar1[0x9d],"TIFFLinkDirectory",s_Error_writing_SubIFD_directory_l_00a0a774);
        return 0;
      }
      *(short *)(puVar1 + 0x76) = *(short *)(puVar1 + 0x76) + -1;
      if (*(short *)(puVar1 + 0x76) == 0) {
LAB_0065d78b:
        puVar1[3] = puVar1[3] & 0xffffdfff;
        return 1;
      }
      bVar8 = 0xfffffffb < (uint)puVar1[0x78];
      iVar2 = puVar1[0x78] + 4;
    }
    else {
      uStack_c = puVar1[5];
      if ((uVar7 & 0x80) != 0) {
        FUN_0065a620(&uStack_10);
      }
      (*(code *)puVar1[0xa0])(puVar1[0x9d],puVar1[0x78],puVar1[0x79],0);
      iVar2 = (*(code *)puVar1[0x9f])(puVar1[0x9d],&uStack_10,8);
      if (iVar2 != 8) {
        FUN_006512e0(puVar1[0x9d],"TIFFLinkDirectory",s_Error_writing_SubIFD_directory_l_00a0a774);
        return 0;
      }
      *(short *)(puVar1 + 0x76) = *(short *)(puVar1 + 0x76) + -1;
      if (*(short *)(puVar1 + 0x76) == 0) goto LAB_0065d78b;
      bVar8 = 0xfffffff7 < (uint)puVar1[0x78];
      iVar2 = puVar1[0x78] + 8;
    }
    puVar1[0x78] = iVar2;
    puVar1[0x79] = puVar1[0x79] + (uint)bVar8;
  }
  return 1;
}

