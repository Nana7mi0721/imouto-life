
int * FUN_006500d0(char *param_1,char *param_2,int param_3,int param_4,int param_5,int param_6,
                  int param_7,int param_8,int param_9,int param_10)

{
  undefined2 *puVar1;
  char cVar2;
  short sVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int *piVar8;
  char *pcVar9;
  char *pcVar10;
  int *piVar11;
  uint local_8 [2];
  
  local_8[0] = FUN_00650070(param_2,"TIFFClientOpen");
  if (local_8[0] == 0xffffffff) {
    return (int *)0x0;
  }
  uVar6 = 0xffffffff;
  pcVar9 = param_1;
  do {
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    cVar2 = *pcVar9;
    pcVar9 = pcVar9 + 1;
  } while (cVar2 != '\0');
  piVar4 = (int *)FUN_006507d0(~uVar6 + 0x2b8);
  if (piVar4 == (int *)0x0) {
    FUN_006512e0(param_3,"TIFFClientOpen",s__s__Out_of_memory__TIFF_structur_00a06b28,param_1);
    return (int *)0x0;
  }
  FUN_00650810(piVar4,0,0x2b8);
  uVar6 = 0xffffffff;
  *piVar4 = (int)(piVar4 + 0xae);
  pcVar9 = param_1;
  do {
    pcVar10 = pcVar9;
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    pcVar10 = pcVar9 + 1;
    cVar2 = *pcVar9;
    pcVar9 = pcVar10;
  } while (cVar2 != '\0');
  uVar6 = ~uVar6;
  piVar8 = (int *)(pcVar10 + -uVar6);
  piVar11 = piVar4 + 0xae;
  for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
    *piVar11 = *piVar8;
    piVar8 = piVar8 + 1;
    piVar11 = piVar11 + 1;
  }
  for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(char *)piVar11 = (char)*piVar8;
    piVar8 = (int *)((int)piVar8 + 1);
    piVar11 = (int *)((int)piVar11 + 1);
  }
  piVar4[0x72] = 0;
  piVar4[0x73] = 0;
  piVar4[0x71] = -1;
  piVar4[0x6f] = -1;
  piVar4[2] = local_8[0] & 0xfffffcff;
  *(undefined2 *)(piVar4 + 0x70) = 0xffff;
  piVar4[0x9d] = param_3;
  if ((((param_4 == 0) || (param_5 == 0)) || (param_6 == 0)) || ((param_7 == 0 || (param_8 == 0))))
  {
    FUN_006512e0(param_3,"TIFFClientOpen",s_One_of_the_client_procedures_is_N_00a06a04);
    return (int *)0x0;
  }
  piVar4[0x9e] = param_4;
  piVar4[0x9f] = param_5;
  piVar4[0xa0] = param_6;
  piVar4[0xa1] = param_7;
  piVar4[0xa2] = param_8;
  if (param_9 == 0) {
    piVar4[0x9b] = (int)FUN_0060b400;
  }
  else {
    piVar4[0x9b] = param_9;
  }
  if (param_10 == 0) {
    piVar4[0x9c] = (int)FUN_0065f670;
  }
  else {
    piVar4[0x9c] = param_10;
  }
  FUN_00653bb0(piVar4);
  piVar4[3] = 1;
  if (local_8[0] == 0) {
    piVar4[3] = 0x801;
LAB_00650263:
    piVar4[3] = piVar4[3] | 0x8000;
  }
  else if (local_8[0] == 2) goto LAB_00650263;
  cVar2 = *param_2;
  pcVar9 = param_2;
  while (cVar2 != '\0') {
    switch(*pcVar9) {
    case '8':
      if ((local_8[0] & 0x100) != 0) {
        uVar6 = piVar4[3] | 0x80000;
        goto LAB_006502fe;
      }
      break;
    case 'B':
      uVar6 = piVar4[3] & 0xfffffffdU | 1;
      goto LAB_006502fe;
    case 'C':
      if (local_8[0] == 0) {
        uVar6 = piVar4[3] | 0x8000;
        goto LAB_006502fe;
      }
      break;
    case 'H':
    case 'L':
      uVar6 = piVar4[3] & 0xfffffffeU | 2;
      goto LAB_006502fe;
    case 'M':
      if (local_8[0] == 0) {
        uVar6 = piVar4[3] | 0x800;
        goto LAB_006502fe;
      }
      break;
    case 'b':
      if ((local_8[0] & 0x100) != 0) {
        uVar6 = piVar4[3] | 0x80;
        goto LAB_006502fe;
      }
      break;
    case 'c':
      if (local_8[0] == 0) {
        uVar6 = piVar4[3] & 0xffff7fff;
        goto LAB_006502fe;
      }
      break;
    case 'h':
      uVar6 = piVar4[3] | 0x10000;
LAB_006502fe:
      piVar4[3] = uVar6;
      break;
    case 'm':
      if (local_8[0] == 0) {
        uVar6 = piVar4[3] & 0xfffff7ff;
        goto LAB_006502fe;
      }
    }
    pcVar10 = pcVar9 + 1;
    pcVar9 = pcVar9 + 1;
    cVar2 = *pcVar10;
  }
  if ((local_8[0] & 0x200) == 0) {
    iVar5 = (*(code *)piVar4[0x9e])(piVar4[0x9d],piVar4 + 0x6a,8);
    if (iVar5 == 8) {
      sVar3 = (short)piVar4[0x6a];
      if (sVar3 == 0x4d4d) {
        piVar4[3] = piVar4[3] | 0x80;
      }
      else if (sVar3 != 0x4949) {
        FUN_006512e0(piVar4[0x9d],param_1,s_Not_a_TIFF_file__bad_magic_numbe_00a06afc,sVar3,sVar3);
        goto LAB_006506f2;
      }
      if ((*(byte *)(piVar4 + 3) & 0x80) != 0) {
        FUN_0065a5f0((int)piVar4 + 0x1aa);
      }
      sVar3 = *(short *)((int)piVar4 + 0x1aa);
      if ((sVar3 != 0x2a) && (sVar3 != 0x2b)) {
        FUN_006512e0(piVar4[0x9d],param_1,s_Not_a_TIFF_file__bad_version_num_00a06acc,sVar3,sVar3);
        goto LAB_006506f2;
      }
      if (sVar3 == 0x2a) {
        if ((*(byte *)(piVar4 + 3) & 0x80) != 0) {
          FUN_0065a600(piVar4 + 0x6b);
        }
        *(undefined2 *)(piVar4 + 0x6e) = 8;
      }
      else {
        iVar5 = (*(code *)piVar4[0x9e])(piVar4[0x9d],piVar4 + 0x6c,8);
        if (iVar5 != 8) {
          FUN_006512e0(piVar4[0x9d],param_1,s_Cannot_read_TIFF_header_00a06ab4);
          goto LAB_006506f2;
        }
        if ((*(byte *)(piVar4 + 3) & 0x80) != 0) {
          FUN_0065a5f0(piVar4 + 0x6b);
          FUN_0065a620(piVar4 + 0x6c);
        }
        sVar3 = (short)piVar4[0x6b];
        if (sVar3 != 8) {
          FUN_006512e0(piVar4[0x9d],param_1,s_Not_a_TIFF_file__bad_BigTIFF_off_00a06a80,sVar3,sVar3)
          ;
          goto LAB_006506f2;
        }
        sVar3 = *(short *)((int)piVar4 + 0x1ae);
        if (sVar3 != 0) {
          FUN_006512e0(piVar4[0x9d],param_1,s_Not_a_TIFF_file__bad_BigTIFF_unu_00a06a50,sVar3,sVar3)
          ;
          goto LAB_006506f2;
        }
        *(undefined2 *)(piVar4 + 0x6e) = 0x10;
        piVar4[3] = piVar4[3] | 0x80000;
      }
      uVar6 = piVar4[3];
      piVar4[3] = uVar6 | 0x200;
      piVar4[0x93] = 0;
      piVar4[0x97] = 0;
      piVar4[0x94] = 0;
      piVar4[0x95] = 0;
      piVar4[0x96] = 0;
      if (*param_2 == 'a') {
        iVar5 = FUN_0064e540(piVar4);
        if (iVar5 != 0) {
          return piVar4;
        }
      }
      else if (*param_2 == 'r') {
        if ((uVar6 & 0x80000) == 0) {
          piVar4[6] = piVar4[0x6b];
          piVar4[7] = 0;
        }
        else {
          piVar4[6] = piVar4[0x6c];
          piVar4[7] = piVar4[0x6d];
        }
        if ((uVar6 & 0x800) != 0) {
          iVar5 = (*(code *)piVar4[0x9b])(piVar4[0x9d],piVar4 + 0x99,local_8);
          if (iVar5 == 0) {
            piVar4[3] = piVar4[3] & 0xfffff7ff;
          }
          else {
            piVar4[0x9a] = local_8[0];
          }
        }
        if ((piVar4[3] & 0x10000U) != 0) {
          return piVar4;
        }
        iVar5 = FUN_00653d10(piVar4);
        if (iVar5 != 0) {
          piVar4[0x98] = -1;
          piVar4[3] = piVar4[3] | 0x10;
          return piVar4;
        }
      }
      goto LAB_006506f2;
    }
  }
  if (piVar4[2] == 0) {
    FUN_006512e0(piVar4[0x9d],param_1,s_Cannot_read_TIFF_header_00a06ab4);
  }
  else {
    piVar8 = piVar4 + 0x6a;
    uVar6 = piVar4[3] & 0x80;
    *(ushort *)piVar8 = (-(ushort)(uVar6 != 0) & 0x404) + 0x4949;
    puVar1 = (undefined2 *)((int)piVar4 + 0x1aa);
    if ((piVar4[3] & 0x80000U) == 0) {
      *puVar1 = 0x2a;
      piVar4[0x6b] = 0;
      if (uVar6 != 0) {
        FUN_0065a5f0(puVar1);
      }
      *(undefined2 *)(piVar4 + 0x6e) = 8;
    }
    else {
      piVar4[0x6c] = 0;
      *puVar1 = 0x2b;
      *(undefined2 *)(piVar4 + 0x6b) = 8;
      *(undefined2 *)((int)piVar4 + 0x1ae) = 0;
      piVar4[0x6d] = 0;
      if (uVar6 != 0) {
        FUN_0065a5f0(puVar1);
        FUN_0065a5f0(piVar4 + 0x6b);
      }
      *(undefined2 *)(piVar4 + 0x6e) = 0x10;
    }
    (*(code *)piVar4[0xa0])(piVar4[0x9d],0,0,0);
    uVar6 = (*(code *)piVar4[0x9f])(piVar4[0x9d],piVar8,(short)piVar4[0x6e]);
    if (uVar6 == *(ushort *)(piVar4 + 0x6e)) {
      if ((short)*piVar8 == 0x4d4d) {
        piVar4[3] = piVar4[3] | 0x80;
      }
      iVar5 = FUN_0064e540(piVar4);
      if (iVar5 != 0) {
        piVar4[4] = 0;
        piVar4[5] = 0;
        piVar4[8] = 0;
        *(undefined2 *)(piVar4 + 9) = 0;
        *(undefined2 *)((int)piVar4 + 0x26) = 0;
        return piVar4;
      }
    }
    else {
      FUN_006512e0(piVar4[0x9d],param_1,s_Error_writing_TIFF_header_00a06a34);
    }
  }
LAB_006506f2:
  piVar4[2] = 0;
  FUN_00646bb0(piVar4);
  return (int *)0x0;
}

