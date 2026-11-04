
uint FUN_00655fd0(undefined4 *param_1,undefined4 *param_2,int param_3,int *param_4,
                 undefined4 *param_5)

{
  int iVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined2 extraout_var;
  ushort uVar7;
  undefined8 *puVar8;
  undefined4 *puVar9;
  undefined2 *puVar10;
  undefined8 uVar11;
  undefined4 *puVar12;
  char *pcVar13;
  undefined2 *local_4;
  
  puVar12 = param_5;
  puVar2 = param_1;
  param_1[4] = param_2;
  param_1[5] = param_3;
  if (param_5 != (undefined4 *)0x0) {
    *param_5 = 0;
    param_5[1] = 0;
  }
  if ((param_1[3] & 0x800) == 0) {
    uVar11 = (*(code *)param_1[0xa0])(param_1[0x9d],param_1[4],param_1[5],0);
    if (((int)uVar11 != puVar2[4]) || ((int)((ulonglong)uVar11 >> 0x20) != puVar2[5])) {
      uVar3 = FUN_006512e0(puVar2[0x9d],"TIFFFetchDirectory",
                           s__s__Seek_error_accessing_TIFF_di_00a0a458,*puVar2);
      return uVar3 & 0xffff0000;
    }
    if ((puVar2[3] & 0x80000) == 0) {
      iVar4 = (*(code *)puVar2[0x9e])(puVar2[0x9d],&param_1,2);
      if (iVar4 != 2) {
        uVar3 = FUN_006512e0(puVar2[0x9d],"TIFFFetchDirectory",
                             s__s__Can_not_read_TIFF_directory_c_00a0a430,*puVar2);
        return uVar3 & 0xffff0000;
      }
      if ((*(byte *)(puVar2 + 3) & 0x80) != 0) {
        FUN_0065a5f0(&param_1);
      }
      if (0x1000 < (ushort)param_1) {
LAB_006562d3:
        uVar3 = FUN_006512e0(puVar2[0x9d],"TIFFFetchDirectory",
                             s_Sanity_check_on_directory_count_f_00a0a380);
        return uVar3 & 0xffff0000;
      }
      iVar4 = 0xc;
    }
    else {
      iVar4 = (*(code *)puVar2[0x9e])(puVar2[0x9d],&param_2,8);
      if (iVar4 != 8) {
        uVar3 = FUN_006512e0(puVar2[0x9d],"TIFFFetchDirectory",
                             s__s__Can_not_read_TIFF_directory_c_00a0a430,*puVar2);
        return uVar3 & 0xffff0000;
      }
      if ((*(byte *)(puVar2 + 3) & 0x80) != 0) {
        FUN_0065a620(&param_2);
      }
      if ((param_3 != 0) || ((undefined4 *)0x1000 < param_2)) goto LAB_006562d3;
      param_1 = param_2;
      iVar4 = 0x14;
    }
    local_4 = (undefined2 *)
              FUN_00650c00(puVar2,(uint)param_1 & 0xffff,iVar4,s_to_read_TIFF_directory_00a0a418);
    uVar3 = 0;
    if (local_4 == (undefined2 *)0x0) goto LAB_0065661a;
    iVar5 = (*(code *)puVar2[0x9e])(puVar2[0x9d],local_4,((uint)param_1 & 0xffff) * iVar4);
    if (iVar5 != ((uint)param_1 & 0xffff) * iVar4) {
      FUN_006512e0(puVar2[0x9d],"TIFFFetchDirectory",s___100s__Can_not_read_TIFF_direct_00a0a3f4,
                   *puVar2);
      uVar3 = FUN_006507e0(local_4);
      return uVar3 & 0xffff0000;
    }
    if (puVar12 == (undefined4 *)0x0) goto LAB_006564cb;
    if ((puVar2[3] & 0x80000) == 0) {
      iVar4 = (*(code *)puVar2[0x9e])(puVar2[0x9d],&param_5,4);
      if (iVar4 != 4) {
        param_5 = (undefined4 *)0x0;
      }
      if ((*(byte *)(puVar2 + 3) & 0x80) != 0) {
        FUN_0065a600(&param_5);
      }
      *puVar12 = param_5;
      puVar12[1] = 0;
      goto LAB_006564cb;
    }
    iVar4 = (*(code *)puVar2[0x9e])(puVar2[0x9d],puVar12,8);
    if (iVar4 != 8) {
      *puVar12 = 0;
      puVar12[1] = 0;
    }
    if ((*(byte *)(puVar2 + 3) & 0x80) == 0) goto LAB_006564cb;
LAB_006564c3:
    FUN_0065a620(puVar12);
LAB_006564cb:
    param_5 = (undefined4 *)
              FUN_00650c00(puVar2,(uint)param_1 & 0xffff,0x18,s_to_read_TIFF_directory_00a0a418);
    if (param_5 == (undefined4 *)0x0) {
      uVar3 = FUN_006507e0(local_4);
      return uVar3 & 0xffff0000;
    }
    uVar7 = 0;
    if ((ushort)param_1 != 0) {
      puVar8 = (undefined8 *)((int)param_5 + 8);
      puVar10 = local_4;
      do {
        if ((*(byte *)(puVar2 + 3) & 0x80) != 0) {
          FUN_0065a5f0(puVar10);
        }
        *(undefined2 *)(puVar8 + -1) = *puVar10;
        if ((*(byte *)(puVar2 + 3) & 0x80) != 0) {
          FUN_0065a5f0(puVar10 + 1);
        }
        puVar12 = (undefined4 *)(puVar10 + 2);
        *(undefined2 *)((int)puVar8 + -6) = puVar10[1];
        uVar3 = puVar2[3];
        if ((uVar3 & 0x80000) == 0) {
          if ((uVar3 & 0x80) != 0) {
            FUN_0065a600(puVar12);
          }
          puVar9 = (undefined4 *)(puVar10 + 4);
          *(undefined4 *)puVar8 = *puVar12;
          *(undefined4 *)((int)puVar8 + 4) = 0;
          puVar10 = puVar10 + 6;
          *(undefined4 *)(puVar8 + 1) = *puVar9;
        }
        else {
          if ((uVar3 & 0x80) != 0) {
            FUN_0065a620(puVar12);
          }
          uVar11 = FUN_00656630(puVar12);
          *puVar8 = uVar11;
          uVar11 = FUN_00656630(puVar10 + 6);
          puVar8[1] = uVar11;
          puVar10 = puVar10 + 10;
        }
        puVar8 = puVar8 + 3;
        uVar7 = uVar7 + 1;
      } while (uVar7 < (ushort)param_1);
    }
    FUN_006507e0(local_4);
    *param_4 = (int)param_5;
    return CONCAT22(extraout_var,(ushort)param_1);
  }
  iVar4 = param_1[4];
  if (iVar4 >> 0x1f != param_1[5]) {
    uVar3 = FUN_006512e0(param_1[0x9d],"TIFFFetchDirectory",
                         s_Can_not_read_TIFF_directory_coun_00a0a3d0);
    return uVar3 & 0xffff0000;
  }
  if ((param_1[3] & 0x80000) == 0) {
    iVar5 = iVar4 + 2;
    if (((iVar4 <= iVar5) && (1 < iVar5)) && (iVar5 <= (int)param_1[0x9a])) {
      FUN_00650840(&param_1,iVar4 + param_1[0x99],2);
      if ((*(byte *)(puVar2 + 3) & 0x80) != 0) {
        FUN_0065a5f0(&param_1);
      }
      if (0x1000 < (ushort)param_1) goto LAB_006562d3;
      iVar4 = 0xc;
LAB_0065636e:
      if ((short)param_1 == 0) {
        uVar3 = FUN_006512e0(puVar2[0x9d],"TIFFFetchDirectory",
                             s_Sanity_check_on_directory_count_f_00a0a334);
        return uVar3 & 0xffff0000;
      }
      local_4 = (undefined2 *)
                FUN_00650c00(puVar2,(uint)param_1 & 0xffff,iVar4,s_to_read_TIFF_directory_00a0a418);
      uVar3 = 0;
      if (local_4 == (undefined2 *)0x0) goto LAB_0065661a;
      iVar6 = ((uint)param_1 & 0xffff) * iVar4;
      iVar1 = iVar6 + iVar5;
      if (((iVar1 < iVar5) || (iVar1 < iVar6)) || ((int)puVar2[0x9a] < iVar1)) {
        FUN_006512e0(puVar2[0x9d],"TIFFFetchDirectory",s_Can_not_read_TIFF_directory_00a0a318);
        uVar3 = FUN_006507e0(local_4);
        return uVar3 & 0xffff0000;
      }
      FUN_00650840(local_4,iVar5 + puVar2[0x99],iVar6);
      if (param_5 == (undefined4 *)0x0) goto LAB_006564cb;
      iVar5 = iVar5 + ((uint)param_1 & 0xffff) * iVar4;
      if ((puVar2[3] & 0x80000) == 0) {
        iVar4 = iVar5 + 4;
        if (((iVar4 < iVar5) || (iVar4 < 4)) || ((int)puVar2[0x9a] < iVar4)) {
          param_2 = (undefined4 *)0x0;
        }
        else {
          FUN_00650840(&param_2,iVar5 + puVar2[0x99],4);
        }
        if ((*(byte *)(puVar2 + 3) & 0x80) != 0) {
          FUN_0065a600(&param_2);
        }
        *param_5 = param_2;
        param_5[1] = 0;
        goto LAB_006564cb;
      }
      iVar4 = iVar5 + 8;
      if (((iVar4 < iVar5) || (iVar4 < 8)) || ((int)puVar2[0x9a] < iVar4)) {
        *param_5 = 0;
        param_5[1] = 0;
      }
      else {
        FUN_00650840(param_5,iVar5 + puVar2[0x99],8);
      }
      if ((*(byte *)(puVar2 + 3) & 0x80) == 0) goto LAB_006564cb;
      puVar12 = param_5;
      goto LAB_006564c3;
    }
LAB_00656601:
    pcVar13 = s_Can_not_read_TIFF_directory_coun_00a0a3d0;
  }
  else {
    iVar5 = iVar4 + 8;
    if (((iVar5 < iVar4) || (iVar5 < 8)) || ((int)param_1[0x9a] < iVar5)) goto LAB_00656601;
    FUN_00650840(&param_2,iVar4 + param_1[0x99],8);
    if ((*(byte *)(puVar2 + 3) & 0x80) != 0) {
      FUN_0065a620(&param_2);
    }
    if ((param_3 == 0) && (param_2 < (undefined4 *)0x1001)) {
      param_1 = param_2;
      iVar4 = 0x14;
      goto LAB_0065636e;
    }
    pcVar13 = s_Sanity_check_on_directory_count_f_00a0a380;
  }
  uVar3 = FUN_006512e0(puVar2[0x9d],"TIFFFetchDirectory",pcVar13);
LAB_0065661a:
  return uVar3 & 0xffff0000;
}

